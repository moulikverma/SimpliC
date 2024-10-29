#include "include/AST.h"

AST_T* init_AST(ast_type type){
    AST_T* ast = (AST_T*)calloc(1, sizeof(struct AST_STRUCT));
    ast->type = type;
    
    // AST variable definition
    ast-> variable_definition_variable_name = NULL;
    ast-> variable_definition_value = NULL;

    // AST Variable
    ast-> variable_name = NULL;

    // AST function call
    ast-> function_call_name = NULL;
    ast-> function_call_argument = NULL;
    ast-> function_call_argument_size = 0; 

    // AST string 
    ast-> string_value = NULL;
    return ast;
}