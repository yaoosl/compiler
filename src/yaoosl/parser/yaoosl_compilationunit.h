#pragma once
#include <inttypes.h>
#include <stdbool.h>
#include "yaoosl_cstnode.h"
#include <yaoosl/runtime/yaoosl_code_page.h>
#include "yaoosl_hashmap.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
typedef struct yaoosl_compilationunit {
    yaoosl_cstnode parse_0;

    yaoosl_code_page codepage;
    char** usings;
    size_t usings_size;
    size_t usings_capacity;

    // yaooslcodehandle handle;

    // struct yaoosl_string_stack* sstack;
    bool errored;
    bool debug_symbols;

    char* current_namespace;
    size_t current_namespace_capacity;
    size_t current_namespace_size;

    const char* code;
    size_t code_index;
    size_t code_line;
    size_t code_column;
    const char* code_file;
    uint16_t code_file_len;

    bool is_constructor;
    bool is_void;
    size_t tmp_size;
    bool is_static;




    yaoosl_hashmap var_hashmap;

    uint64_t* break_offsets;
    size_t  break_offsets_size;
    size_t  break_offsets_capacity;

    uint64_t* continue_offsets;
    size_t  continue_offsets_size;
    size_t  continue_offsets_capacity;

    int64_t* jump_offsets;
    size_t  jump_offsets_size;
    size_t  jump_offsets_capacity;
} yaoosl_compilationunit;

enum yaoosl_compilation_result
{
    YSCMPRES_OK,
    YSCMPRES_ERROR,
    YSCMPRES_OUT_OF_MEMORY,
};

enum yaoosl_compilation_result yaoosl_compilation_parse_0(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size);
enum yaoosl_compilation_result yaoosl_compilation_parse_1(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size);
enum yaoosl_compilation_result yaoosl_compilation_parse(yaoosl_compilationunit* ycu, const char* path, const char* contents, size_t contents_size);


#ifdef __cplusplus
}
#endif // __cplusplus