#ifndef OTO_LEXER_H
#define OTO_LEXER_H

#include "token.h"

typedef struct {
    const char* start;
    const char* current;
    int line;
} Lexer;

void initLexer(Lexer* lexer, const char* source);
Token scanToken(Lexer* lexer);

#endif