#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>

lexer_T* init_lexer(char* contents){

    lexer_T* lexer = calloc(1,sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->index = 0;
    lexer->ch = contents[lexer->index];

    return lexer;

}

void lexer_advance(lexer_T* lexer){
    
    if(lexer->ch != '\0' && lexer->index < strlen(lexer->contents)){
        lexer->index += 1;
        lexer->ch = lexer->contents[lexer->index];
    }
}

void lexer_skip_whitespace(lexer_T* lexer){
    while(lexer->ch == ' ' || lexer->ch == 10){
        lexer_advance(lexer);
    }
}

token_T* lexer_get_next_token(lexer_T* lexer);

token_T* lexer_collect_string(lexer_T* lexer);

token_T* lexer_collect_id(lexer_T* lexer);

token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token);

char* lexer_get_current_char_as_string(lexer_T* lexer);