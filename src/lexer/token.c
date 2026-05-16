#include "token.h"

const char* tokenTypeToString(TokenType type) {
    switch (type) {
        case TOKEN_VAR: return "TOKEN_VAR";
        case TOKEN_WRITE: return "TOKEN_WRITE";

        case TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
        case TOKEN_NUMBER: return "TOKEN_NUMBER";
        case TOKEN_STRING: return "TOKEN_STRING";

        case TOKEN_EQUAL: return "TOKEN_EQUAL";
        case TOKEN_GREATER: return "TOKEN_GREATER";

        case TOKEN_PLUS: return "TOKEN_PLUS";
        case TOKEN_MINUS: return "TOKEN_MINUS";
        case TOKEN_STAR: return "TOKEN_STAR";
        case TOKEN_SLASH: return "TOKEN_SLASH";

        case TOKEN_LEFT_PAREN: return "TOKEN_LEFT_PAREN";
        case TOKEN_RIGHT_PAREN: return "TOKEN_RIGHT_PAREN";

        case TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";

        case TOKEN_EOF: return "TOKEN_EOF";
        case TOKEN_ERROR: return "TOKEN_ERROR";

        default: return "TOKEN_UNKNOWN";
    }
}