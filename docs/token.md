# oto tokens

This document defines the initial token set for the oto language.

Tokens are the smallest meaningful units produced by the lexer. The lexer reads raw source code and converts it into a sequence of tokens that can later be consumed by the parser.

## keywords

Keywords are reserved words with predefined meaning in the language. They are recognized directly by the lexer and cannot be used as identifiers.

| Source | Token |
|---|---|
| `var` | `TOKEN_VAR` |
| `write` | `TOKEN_WRITE` |

## literals

Literal tokens represent direct runtime values written in source code. At the current stage of the project, oto supports identifiers, numeric literals, and string literals.

```txt
TOKEN_IDENTIFIER
TOKEN_NUMBER
TOKEN_STRING
```

Examples:

```oto
x
message
42
"hello world"
```

- `TOKEN_IDENTIFIER` represents variable names.
- `TOKEN_NUMBER` represents numeric values.
- `TOKEN_STRING` represents text enclosed in double quotes.

## symbols

Symbols represent operators, punctuation, and structural characters used by the grammar.

```txt
TOKEN_EQUAL
TOKEN_GREATER

TOKEN_PLUS
TOKEN_MINUS
TOKEN_STAR
TOKEN_SLASH

TOKEN_LEFT_PAREN
TOKEN_RIGHT_PAREN

TOKEN_SEMICOLON
```

| Source | Token |
|---|---|
| `=` | `TOKEN_EQUAL` |
| `>` | `TOKEN_GREATER` |
| `+` | `TOKEN_PLUS` |
| `-` | `TOKEN_MINUS` |
| `*` | `TOKEN_STAR` |
| `/` | `TOKEN_SLASH` |
| `(` | `TOKEN_LEFT_PAREN` |
| `)` | `TOKEN_RIGHT_PAREN` |
| `;` | `TOKEN_SEMICOLON` |

These tokens help define expressions, grouping rules, assignments, and statement boundaries.

## special tokens

Special tokens are generated internally by the lexer and are not directly written by the programmer.

```txt
TOKEN_EOF
TOKEN_ERROR
```

- `TOKEN_EOF` marks the end of the source file.
- `TOKEN_ERROR` represents invalid or malformed input detected during lexing.

These tokens simplify parser control flow and error reporting.

## example

Source:

```oto
var x = 10;
write > x + 2;
```

Generated tokens:

```txt
VAR
IDENTIFIER(x)
EQUAL
NUMBER(10)
SEMICOLON

WRITE
GREATER
IDENTIFIER(x)
PLUS
NUMBER(2)
SEMICOLON

EOF
```

This token stream is later consumed by the parser to construct the AST.