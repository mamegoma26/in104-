#ifndef CYOL_LEXER_H
#define CYOL_LEXER_H
#include <stdint.h>
#include <stdlib.h>
/**
id: [a-zA-Z][a-zA-Z0-9_]*
type: 'number'| 'string'| 'boolean'  //a adapter au theme
declaration: {id} ':' {type} ';' // a modifier 
 number:[0-9]+[.0-9]*
 expression:{id} |
 assignment:{id} '=' {expression} // a modifier 
 print: 'print'{expression} ';' // a modifier 
*/
typedef enum {
    TOKEN_ID,
    TOKEN_TYPE,
    TOKEN_COLON,
    TOKEN_SEMICOLON,
    TOKEN_VALUE,
    TOKEN_PRINT,
    TOKEN_UNKNOWN
}TokenType;
typedef struct {
    uint8_t *val;
    TokenType type;
}Token;
typedef struct Tokens{
    Token token;
    struct Tokens *prev;
}Tokens;
uint8_t *read_entry(char* filename);
Tokens *new_tokens();
void add_token(Tokens **tokens,uint8_t *val,size_t size_val);
#endif //CYOL_LEXER_H
