#include "lexer.h"

#include <string.h>

static int isAtEnd(Lexer* lexer) {
    return *lexer->current == '\0';
}

static int isDigit(char c) {
    return c >= '0' && c <= '9';
}

static int isAlpha(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
}

static int isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}

static char advance(Lexer* lexer) {
    lexer->current++;
    return lexer->current[-1];
}

static char peek(Lexer* lexer) {
    return *lexer->current;
}

static Token makeToken(Lexer* lexer, TokenType type) {
    Token token;
    token.type = type;
    token.start = lexer->start;
    token.length = (int)(lexer->current - lexer->start);
    token.line = lexer->line;
    return token;
}

static Token errorToken(Lexer* lexer, const char* message) {
    Token token;
    token.type = TOKEN_ERROR;
    token.start = message;
    token.length = (int)strlen(message);
    token.line = lexer->line;
    return token;
}

static void skipWhitespace(Lexer* lexer) {
    for (;;) {
        char c = peek(lexer);

        switch (c) {
            case ' ':
            case '\r':
            case '\t':
                advance(lexer);
                break;

            case '\n':
                lexer->line++;
                advance(lexer);
                break;

            default:
                return;
        }
    }
}

static Token string(Lexer* lexer) {
    while (peek(lexer) != '"' && !isAtEnd(lexer)) {
        if (peek(lexer) == '\n') {
            lexer->line++;
        }

        advance(lexer);
    }

    if (isAtEnd(lexer)) {
        return errorToken(lexer, "Unterminated string.");
    }

    advance(lexer);

    return makeToken(lexer, TOKEN_STRING);
}

static Token number(Lexer* lexer) {
    while (isDigit(peek(lexer))) {
        advance(lexer);
    }

    return makeToken(lexer, TOKEN_NUMBER);
}

static TokenType checkKeyword(
    Lexer* lexer,
    int start,
    int length,
    const char* rest,
    TokenType type
) {
    int tokenLength = (int)(lexer->current - lexer->start);

    if (tokenLength == start + length &&
        memcmp(lexer->start + start, rest, length) == 0) {
        return type;
    }

    return TOKEN_IDENTIFIER;
}

static TokenType identifierType(Lexer* lexer) {
    switch (lexer->start[0]) {
        case 'v':
            return checkKeyword(lexer, 1, 2, "ar", TOKEN_VAR);

        case 'w':
            return checkKeyword(lexer, 1, 4, "rite", TOKEN_WRITE);

        default:
            return TOKEN_IDENTIFIER;
    }
}

static Token identifier(Lexer* lexer) {
    while (isAlphaNumeric(peek(lexer))) {
        advance(lexer);
    }

    return makeToken(lexer, identifierType(lexer));
}

void initLexer(Lexer* lexer, const char* source) {
    lexer->start = source;
    lexer->current = source;
    lexer->line = 1;
}

Token scanToken(Lexer* lexer) {
    skipWhitespace(lexer);

    lexer->start = lexer->current;

    if (isAtEnd(lexer)) {
        return makeToken(lexer, TOKEN_EOF);
    }

    char c = advance(lexer);

    if (isAlpha(c)) {
        return identifier(lexer);
    }

    if (isDigit(c)) {
        return number(lexer);
    }

    switch (c) {
        case '(': return makeToken(lexer, TOKEN_LEFT_PAREN);
        case ')': return makeToken(lexer, TOKEN_RIGHT_PAREN);

        case '+': return makeToken(lexer, TOKEN_PLUS);
        case '-': return makeToken(lexer, TOKEN_MINUS);
        case '*': return makeToken(lexer, TOKEN_STAR);
        case '/': return makeToken(lexer, TOKEN_SLASH);

        case '=': return makeToken(lexer, TOKEN_EQUAL);
        case '>': return makeToken(lexer, TOKEN_GREATER);

        case ';': return makeToken(lexer, TOKEN_SEMICOLON);

        case '"': return string(lexer);
    }

    return errorToken(lexer, "Unexpected character.");
}