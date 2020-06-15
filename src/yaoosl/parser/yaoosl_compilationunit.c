#include "yaoosl_compilationunit.h"
#include "yaoosl.tab.h"
#include "yaoosl_compilationunit.h"
#include "yaoosl_cstnode.h"

#include <string.h>

#define PUSH(PROP, VAL, TMP, ABORT) {\
    if (PROP ## _capacity == PROP ## _size)\
    {\
        TMP = realloc(PROP, sizeof(size_t) * (PROP ## _capacity + PROP ## _capacity + 1));\
        if (!TMP)\
        {\
            ABORT;\
            return YSCMPRES_OUT_OF_MEMORY;\
        }\
        PROP = TMP;\
        PROP ## _capacity = PROP ## _capacity + PROP ## _capacity + 1;\
    }\
    PROP[PROP ## _size++] = VAL;\
}
#define POP(PROP, OUTVAL, ABORT) {\
    if (PROP ## _size == 0) { ABORT; return YSCMPRES_ERROR; }\
    OUTVAL = PROP[PROP ## _size];\
    PROP_size--;\
}

enum yaoosl_compilation_result yaoosl_compilation_parse_0(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size)
{
    yyscan_t scan = { 0 };

    ycu->code = contents;
    ycu->code_file = path;
    ycu->code_file_len = contents_size;
    // yaoosl_debug = 1;
    yaoosl_lex_init(&scan);
    yaoosl_set_extra(ycu, scan);

    yaoosl_parse(scan, ycu);
    if (ycu->errored)
    {
        yaoosl_lex_destroy(scan);
        yaoosl_cstnode_invalidate(&ycu->parse_0);
        return YSCMPRES_ERROR;
    }
    yaoosl_lex_destroy(scan);
    
    yaoosl_yycstnode_printf(ycu->parse_0);
    return YSCMPRES_OK;
}
enum yaoosl_compilation_result yaoosl_compilation_parse_1_read_using(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size, yaoosl_cstnode current)
{
    size_t i;
    size_t len;
    char* str;
    void* tmp;
    switch (current.type)
    {
    case yscst_using: {
        /*
            usingns: "using" identifier ";"              { $$ = CSTNODE(yscst_using); CSTIMP($$, $2); }
                   ;
        */
        // Calculate full length of string
        len = 0;
        for (i = 0; i < current.children_size; i++)
        {
            len += strlen(current.children[i].value) + 1;
        }

        // Allocate memory
        if (!(str = malloc(sizeof(char) * (len + 1))))
        {
            return YSCMPRES_OUT_OF_MEMORY;
        }

        // Copy strings to out temporary string
        tmp = str;
        for (i = 0; i < current.children_size; i++)
        {
            len = strlen(current.children[i].value);
            strncpy(str, current.children[i].value, len);
            str[len] = '.';
            str += len + 1;
        }
        (--str)[0] = '\0';
        str = tmp;

        // Push to usings dir of compilation unit
        PUSH(ycu->usings, str, tmp, free(str));
    } break;
    case yscst_namespace: {
        /*
            nmspc: "namespace" identifier "{" root "}"   { $$ = CSTNODE(yscst_namespace); CSTPSH($$, $2); CSTPSH($$, $4); }
                 ;
        */
        len = 0;
        for (i = 0; i < current.children[0].children_size; i++)
        {
            len += strlen(current.children[0].children[i].value) + 1;
        }

        // Allocate memory
        if (ycu->current_namespace_capacity < ycu->current_namespace_size + len + 1)
        {
            if (!(tmp = realloc(ycu->current_namespace, sizeof(char) * (ycu->current_namespace_size + len + 1))))
            {
                return YSCMPRES_OUT_OF_MEMORY;
            }
            ycu->current_namespace = tmp;
            ycu->current_namespace_capacity = ycu->current_namespace_size + len + 1;
        }

        // Replace ending '\0' with a dot if needed
        if (ycu->current_namespace_size > 0)
        {
            ycu->current_namespace[ycu->current_namespace_size - 1] = '.';
        }

        // Update size value and prepare str pointer
        str = ycu->current_namespace + ycu->current_namespace_size;
        ycu->current_namespace_size += len;

        // Copy strings
        tmp = str;
        for (i = 0; i < current.children[0].children_size; i++)
        {
            len = strlen(current.children[0].children[i].value);
            strncpy(str, current.children[0].children[i].value, len);
            str[len] = '.';
            str += len + 1;
        }
        (--str)[0] = '\0';
        str = tmp;

        // Call child
        yaoosl_compilation_parse_1_read_using(ycu, path, contents, contents_size, current.children[1]);

        // Reset namespace to previous level
        ycu->current_namespace_size = str - ycu->current_namespace;
        ycu->current_namespace[ycu->current_namespace_size == 0 ? ycu->current_namespace_size : ycu->current_namespace_size - 1] = '\0';
    } break;
    case yscst_classdef: {
        /*
            encpsl: "public"                                       { $$ = CSTNODE(yscst_encapsulation_public); }
                  | "internal"                                     { $$ = CSTNODE(yscst_encapsulation_internal); }
                  | "derived"                                      { $$ = CSTNODE(yscst_encapsulation_derived); }
                  | "private"                                      { $$ = CSTNODE(yscst_encapsulation_private); }
                  ;
            classhead: encpsl "class" YST_NAME                     { $$ = CSTNODE(yscst_classhead); CSTPSH($$, $1); CSTPSH($$, CSTNODEV(yscst_ident, $3)); }
                     ;
            classbody: mthd classbody                              { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
                     | mthd                                        { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
                     | cnstmthd classbody                          { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
                     | cnstmthd                                    { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
                     | opmthd classbody                            { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
                     | opmthd                                      { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
                     | property classbody                          { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); CSTIMP($$, $2); }
                     | property                                    { $$ = CSTNODE(yscst_classbody); CSTPSH($$, $1); }
                     | "extern" mthd classbody                     { $$ = CSTNODE(yscst_classbody); CSTPSH($$, CSTNODE(yscst_extern)); CSTPSH($$, $2); CSTIMP($$, $3); }
                     | "extern" mthd                               { $$ = CSTNODE(yscst_classbody); CSTPSH($$, CSTNODE(yscst_extern)); CSTPSH($$, $2); }
                     | "extern" cnstmthd classbody                 { $$ = CSTNODE(yscst_classbody); CSTPSH($$, CSTNODE(yscst_extern)); CSTPSH($$, $2); CSTIMP($$, $3); }
                     | "extern" cnstmthd                           { $$ = CSTNODE(yscst_classbody); CSTPSH($$, CSTNODE(yscst_extern)); CSTPSH($$, $2); }
                     | "extern" opmthd classbody                   { $$ = CSTNODE(yscst_classbody); CSTPSH($$, CSTNODE(yscst_extern)); CSTPSH($$, $2); CSTIMP($$, $3); }
                     | "extern" opmthd                             { $$ = CSTNODE(yscst_classbody); CSTPSH($$, CSTNODE(yscst_extern)); CSTPSH($$, $2); }
                     | "extern" property classbody                 { $$ = CSTNODE(yscst_classbody); CSTPSH($$, CSTNODE(yscst_extern)); CSTPSH($$, $2); CSTIMP($$, $3); }
                     | "extern" property                           { $$ = CSTNODE(yscst_classbody); CSTPSH($$, CSTNODE(yscst_extern)); CSTPSH($$, $2); }
                     | error classbody                             { $$ = CSTNODE(yscst_error); CSTIMP($$, $2); }
                     | error                                       { $$ = CSTNODE(yscst_error); }
                     ;
            classdef: classhead ":" identlist "{" classbody "}"    { $$ = CSTNODE(yscst_classdef); CSTPSH($$, $1); CSTPSH($$, $3); CSTPSH($$, $5); }
                    | classhead "{" classbody "}"                  { $$ = CSTNODE(yscst_classdef); CSTPSH($$, $1); CSTPSH($$, $3); }
                    | classhead ":" identlist "{" "}"              { $$ = CSTNODE(yscst_classdef); CSTPSH($$, $1); CSTPSH($$, $3); }
                    | classhead "{" "}"                            { $$ = CSTNODE(yscst_classdef); CSTPSH($$, $1); }
                    ;
        */
        // Deal with classhead

    } break;
    default:
        for (i = 0; i < current.children_size; i++)
        {
            yaoosl_compilation_parse_1_read_using(ycu, path, contents, contents_size, current.children[i]);
        }
    }
    return YSCMPRES_OK;
}
enum yaoosl_compilation_result yaoosl_compilation_parse_1(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size)
{
    enum yaoosl_compilation_result res;
    size_t i;
    for (i = 0; i < ycu->parse_0.children_size; i++)
    {
        res = yaoosl_compilation_parse_1_read_using(ycu, path, contents, contents_size, ycu->parse_0.children[i]);
        if (res != YSCMPRES_OK)
        {
            return res;
        }
    }
    return YSCMPRES_OK;
}
enum yaoosl_compilation_result yaoosl_compilation_parse(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size)
{
    enum yaoosl_compilation_result res;
    ycu->current_namespace = 0;
    ycu->current_namespace_capacity = 0;
    ycu->current_namespace_size = 0;

    if ((res = yaoosl_compilation_parse_0(ycu, path, contents, contents_size)) != YSCMPRES_OK) { return res; }
    if ((res = yaoosl_compilation_parse_1(ycu, path, contents, contents_size)) != YSCMPRES_OK) { return res; }


    if (ycu->current_namespace_capacity > 0)
    {
        free(ycu->current_namespace);
        ycu->current_namespace = 0;
        ycu->current_namespace_capacity = 0;
        ycu->current_namespace_size = 0;
    }

    return YSCMPRES_OK;
}
