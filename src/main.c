#include <stdio.h>
#include <string.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"
#include "include/io.h"

#define MAX_LIMIT 30
void print_help()
{
    printf("Usage:\nsimplic.out <filename>\n");
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc >= 2){
        for(int i = 1; i < argc; i++){
            int len = strlen(argv[i]);
            char* last_eight = &argv[i][len-8];
            if(strcmp(last_eight,".simplic") == 0){
                                lexer_T* lexer = init_lexer(
                    get_file_contents(argv[i])
                );
                parser_T* parser = init_parser(lexer);
                AST_T* root = parser_parse(parser, parser->scope);
                visitor_T* visitor = init_visitor();
                visitor_visit(visitor, root);
            }

            else {
                print_help();
            }
        }
    }
    else {
        char input[MAX_LIMIT];
        while(1){
            printf("Welcome to the hello language v. 0.0.1!\nCreated by github.com/rahulchy960\n");
            printf("Usage: simplic.out <filename>\n>>> ");
            fgets(input,MAX_LIMIT, stdin);
            lexer_T* lexer = init_lexer(input);
            parser_T* parser = init_parser(lexer);
            AST_T* root = parser_parse(parser, parser->scope);
            visitor_T* visitor = init_visitor();
            visitor_visit(visitor, root);
        }
    }
    return 0;
}

