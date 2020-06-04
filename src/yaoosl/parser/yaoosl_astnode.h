#pragma once
#include <inttypes.h>
#include <stdbool.h>
#include <malloc.h>
#include "yaoosl.tab.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	enum yaoosl_ast_type
	{
		ysast_empty,
		ysast_root,
		ysast_using,
	};
	typedef struct yaoosl_astnode {
		enum yaoosl_ast_type type;

		uint64_t line;
		uint64_t column;
		uint64_t offset;

		char* value;

		struct yaoosl_astnode* children;
		size_t children_capacity;
		size_t children_size;
	} yaoosl_astnode;

	static bool yaoosl_astnode_push_child(yaoosl_astnode* parent, yaoosl_astnode child);
	static void yaoosl_astnode_transfer_to(yaoosl_astnode* astold, yaoosl_astnode* astnew);
	static void yaoosl_astnode_invalidate(yaoosl_astnode* parent);
	// Pushes a child to a parent node.
	static bool yaoosl_astnode_push_child(yaoosl_astnode* parent, yaoosl_astnode child)
	{
		yaoosl_astnode* tmp;
		if (!parent)
		{
			return true;
		}
		if (parent->children_size == parent->children_capacity)
		{

#ifdef __cplusplus
			tmp = (yaoosl_astnode*)realloc(
				parent->children,
				sizeof(yaoosl_astnode) *
				(parent->children_capacity + parent->children_capacity + 1));
#else
			tmp = realloc(
				parent->children,
				sizeof(yaoosl_astnode) *
				(parent->children_capacity + parent->children_capacity + 1));
#endif // __cplusplus
			if (!tmp)
			{
				return false;
			}
			parent->children = tmp;
			parent->children_capacity = parent->children_capacity + parent->children_capacity + 1;
		}
		parent->children[parent->children_size++] = child;
		return true;
	}

	// Moves the left nodes children into the right node, removing the children.
	static void yaoosl_astnode_transfer_to(yaoosl_astnode* astold, yaoosl_astnode* astnew)
	{
		size_t i;
		for (i = 0; i < astold->children_size; i++)
		{
			yaoosl_astnode_push_child(astnew, astold->children[i]);
		}
		astold->children_size = 0;
	}

	// Invalidates the nodes contents,
	// clearing all fields that got allocated using
	// malloc (or similar methods).
	static void yaoosl_astnode_invalidate(yaoosl_astnode* parent)
	{
		size_t index;
		if (!parent)
		{
			return;
		}
		if (parent->value)
		{
			free(parent->value);
			parent->value = 0;
		}
		if (parent->children_size)
		{
			for (index = 0; index < parent->children_size; index++)
			{
				if (parent->children[index].value)
				{
					free(parent->children[index].value);
				}
				yaoosl_astnode_invalidate(parent->children + index);
			}
			free(parent->children);
			parent->children = 0;
			parent->children_capacity = 0;
			parent->children_size = 0;
		}
	}


#ifdef __cplusplus
}
#endif // __cplusplus