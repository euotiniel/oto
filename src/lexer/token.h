#ifndef OTO_TOKEN_H
#define OTO_TOKEN_H

typedef enum {
    TOKEN_VAR,
    TOKEN_WRITE,

    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,

    TOKEN_EQUAL,
    TOKEN_GREATER,

    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,

    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,

    TOKEN_SEMICOLON,

    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    const char* start;
    int length;
    int line;
} Token;

const char* tokenTypeToString(TokenType type);

#endif