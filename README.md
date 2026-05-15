# Oto

Oto is an experimental compiler and runtime study project written in C.

The project is being developed incrementally as a way to study how source code becomes execution: from lexing and parsing to ASTs, bytecode, virtual machines, and runtime systems.

The `.oto` language does not aim to be production-ready or revolutionary. It exists primarily as a vehicle for exploring compiler and runtime engineering concepts from scratch.

The implementation and language design are expected to evolve over time as the project grows.

---

## Current Focus

The current stage of the project does not focus on compilation yet.

Instead, the initial goal is to build the frontend of the language and understand the earliest stages of execution through a tree-walk interpreter architecture.

Current pipeline:

```txt
source file
↓
lexer
↓
tokens
↓
parser
↓
AST
↓
interpreter
```

Current goals:

- Read `.oto` source files
- Implement lexical analysis
- Generate tokens
- Parse expressions and statements
- Build an Abstract Syntax Tree (AST)
- Execute AST nodes using a tree-walk interpreter
- Understand how source code becomes executable structures

---

## Future Evolution

As the project evolves, the interpreter-based architecture is expected to grow into a bytecode compiler and virtual machine system.

Future pipeline:

```txt
source file
↓
lexer
↓
tokens
↓
parser
↓
AST
↓
compiler
↓
bytecode
↓
virtual machine
```

Long-term areas of study include:

- Bytecode compilation
- Virtual machines
- Runtime systems
- Stack frames
- Scope handling
- Runtime object representation
- Heap allocation
- Garbage collection experiments
- Memory management

---

## Project Structure

```txt
oto/
├── README.md
├── Makefile
├── .gitignore
│
├── docs/
│   ├── architecture.md
│   ├── grammar.md
│   ├── philosophy.md
│   └── roadmap.md
│
├── examples/
│   └── hello.oto
│
├── src/
│   ├── main.c
│   │
│   ├── error/
│   │   ├── error.c
│   │   └── error.h
│   │
│   ├── interpreter/
│   │   ├── interpreter.c
│   │   └── interpreter.h
│   │
│   ├── lexer/
│   │   ├── lexer.c
│   │   ├── lexer.h
│   │   ├── token.c
│   │   └── token.h
│   │
│   └── parser/
│       ├── ast.c
│       ├── ast.h
│       ├── parser.c
│       └── parser.h
│
└── tests/
    ├── lexer/
    ├── parser/
    └── interpreter/
```

---

## Status

The project is currently in its earliest stage.

Initial work is focused on:

- Project structure
- Compiler architecture planning
- Language grammar planning
- Token system design
- Lexer implementation