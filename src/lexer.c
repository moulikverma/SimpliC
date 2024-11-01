#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


lexer_T* init_lexer(char* contents)
{
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->index = 0;
    lexer->ch = contents[lexer->index];

    return lexer;
}

void lexer_advance(lexer_T* lexer)
{
    if (lexer->ch != '\0' && lexer->index < strlen(lexer->contents))
    {
        lexer->index += 1;
        lexer->ch = lexer->contents[lexer->index];
    }
}

void lexer_skip_whitespace(lexer_T* lexer)
{
    while (lexer->ch == ' ' || lexer->ch == 10)
    {
        lexer_advance(lexer);
    }
}

token_T* lexer_get_next_token(lexer_T* lexer)
{
    while (lexer->ch != '\0' && lexer->index < strlen(lexer->contents))
    {
        if (lexer->ch == ' ' || lexer->ch == 10)
            lexer_skip_whitespace(lexer);

        if (isalnum(lexer->ch))
            return lexer_collect_id(lexer);

        if (lexer->ch == '"')
            return lexer_collect_string(lexer);

        switch (lexer->ch)
        {
            case '=': return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer))); break;
            case ';': return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_string(lexer))); break;
            case '(': return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_string(lexer))); break;
            case ')': return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_string(lexer))); break;
            case '{': return lexer_advance_with_token(lexer, init_token(TOKEN_LBRACE, lexer_get_current_char_as_string(lexer))); break;
            case '}': return lexer_advance_with_token(lexer, init_token(TOKEN_RBRACE, lexer_get_current_char_as_string(lexer))); break;
            case ',': return lexer_advance_with_token(lexer, init_token(TOKEN_COMMA, lexer_get_current_char_as_string(lexer))); break;
        }
    }

    return init_token(TOKEN_EOF, "\0");
}


token_T* lexer_collect_string(lexer_T* lexer)
{
    lexer_advance(lexer);

    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (lexer->ch != '"')
    {
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        lexer_advance(lexer);
    }

    lexer_advance(lexer);

    return init_token(TOKEN_STRING, value);
}

token_T* lexer_collect_id(lexer_T* lexer)
{
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (isalnum(lexer->ch))
    {
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        lexer_advance(lexer);
    }

    return init_token(TOKEN_ID, value);
}

token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token)
{
    lexer_advance(lexer);

    return token;
}

char* lexer_get_current_char_as_string(lexer_T* lexer)
{
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->ch;
    str[1] = '\0';

    return str;
}