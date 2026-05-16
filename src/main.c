#include <stdio.h>
#include "lexer/lexer.h"
#include "lexer/token.h"

int main(void) {
    const char* source = "var x = 10;\nwrite > x + 2;\n";
    Lexer lexer;
    initLexer(&lexer, source);
    Token token;

    do {
        token = scanToken(&lexer);
        printf("Tipo: %s | Texto: \"%.*s\"\n",
               tokenTypeToString(token.type),
               token.length, token.start);

    } while (token.type != TOKEN_EOF && token.type != TOKEN_ERROR);

    return 0;
}