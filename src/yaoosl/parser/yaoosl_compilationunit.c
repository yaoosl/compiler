#include "yaoosl_compilationunit.h"
#include "yaoosl.tab.h"
#include "yaoosl_compilationunit.h"
#include "yaoosl_cstnode.h"
#include "yaoosl_astnode.h"

#include <string.h>

bool yaoosl_compilation_parse_0(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size)
{
	yyscan_t scan = { 0 };

	ycu->code = contents;
	ycu->code_file = path;
	ycu->code_file_len = contents_size;
	// yaoosl_debug = 1;
	yaoosl_lex_init(&scan);
	yaoosl_set_extra(&ycu, scan);

	yaoosl_parse(scan, ycu);
	if (ycu->errored)
	{
		yaoosl_lex_destroy(scan);
		yaoosl_cstnode_invalidate(&ycu->parse_0);
		return false;
	}
	yaoosl_lex_destroy(scan);
	
	// yaoosl_yycstnode_printf(ycu->parse_0);
	return true;
}

static yaoosl_astnode yaoosl_compilation_parse_1_recursive_cst(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size, yaoosl_cstnode* current)
{
	size_t i;
	size_t len;
	yaoosl_astnode ret = { 0 };
	switch (current->type)
	{
	case yscst_using:
		len = 0;
		for (i = 0; i < current->children_size; i++)
		{
			if (current->children[i].type != yscst_name)
			{
				ycu->errored = true;
				return ret;
			}
			len += strlen(current->children[i].value);
		}
		ret.value = strdup(current->children[0].value);
		break;
	default:
		for (i = 0; i < current->children_size; i++)
		{
			yaoosl_compilation_parse_1_recursive_cst(ycu, path, contents, contents_size, &current->children[i]);
		}
	}
}
bool yaoosl_compilation_parse_1(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size)
{
	return false;
}

bool yaoosl_compilation_parse(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size)
{
	if (!yaoosl_compilation_parse_0(ycu, path, contents, contents_size)) { return false; }
	if (!yaoosl_compilation_parse_1(ycu, path, contents, contents_size)) { return false; }

	return true;
}
