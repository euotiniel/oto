# oto grammar

This document defines the initial grammar for the oto language. 

The grammar is intentionally small. Its purpose is to support the first stage of the project: lexing, parsing, AST construction, and tree-walk interpretation.

## program structure

```txt
program -> statement* EOF
```

An oto program is a sequence of statements followed by the end of the file.

## statements

```txt
statement -> varStmt
           | writeStmt
```

The initial version of oto supports only two statement types:

- variable declarations
- write statements

### var statement

```txt
varStmt -> "var" IDENTIFIER "=" expression ";"
```

Example:

```oto
var x = 10;
```

This statement creates a variable and assigns the result of an expression to it.

### write statement

```txt
writeStmt -> "write" ">" expression ";"
```

Example:

```oto
write > x + 10;
```

The `write` statement evaluates an expression and outputs its result.

## expressions

oto uses a compact flat expression grammar:

```txt
expression -> expression "+" expression
            | expression "-" expression
            | expression "*" expression
            | expression "/" expression
            | "(" expression ")"
            | NUMBER
            | STRING
            | IDENTIFIER
```

The grammar is intentionally left-recursive.

Expressions are parsed using Pratt parsing rather than naive recursive descent parsing. Operator precedence is handled explicitly by the parser through precedence rules.

Current precedence levels:

```txt
* / -> higher precedence
+ - -> lower precedence
```

Example:

```oto
write > 10 + 20 * 3;
```

Interpreted as:

```txt
10 + (20 * 3)
```

Parentheses can override precedence:

```oto
write > (10 + 20) * 3;
```

## string literals

Strings are delimited using double quotes.

```txt
STRING -> "\"" character* "\""
```

Example:

```oto
write > "hello world";
```

At the current stage of the project, strings are treated as literal runtime values that can be passed to `write`.

Escape sequences are not yet supported.

## valid examples

```oto
var x = 10;
var y = 20;

write > x + y * 2;
```

```oto
var message = "hello world";

write > message;
```

## invalid examples

Missing identifier:

```oto
var = 10;
```

```txt
Expected IDENTIFIER after "var"
```

Missing expression:

```oto
var x = ;
```

```txt
Expected expression after "="
```

Missing semicolon:

```oto
write > x
```

```txt
Expected ";" after expression
```

Unterminated string:

```oto
write > "hello world;
```

```txt
Unterminated string literal
```
