#include <stdlib.h>
#ifndef AST_H
#define AST_H

typedef enum{
    AST_VARIABLE_DEFINITION,
    AST_VARIABLE,
    AST_FUNCTION_CALL,
    AST_STRING,
    AST_COMPOUND
}ast_type;

typedef struct AST_STRUCT{

    ast_type type;

    // AST variable definition
    char * variable_definition_variable_name;
    struct AST_STRUCT* variable_definition_value;

    // AST Variable
    char * variable_name;

    // AST function call
    char *function_call_name;
    struct AST_STRUCT** function_call_argument;
    size_t function_call_argument_size; 

    // AST string 
    char* string_value;

    // AST compound
    struct AST_STRUCT** compound_value;
    size_t compound_size;


}AST_T;

AST_T* init_AST(ast_type type);

#endif