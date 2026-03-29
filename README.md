# Ultimate Compiler Project

This project is a beginner-friendly mini compiler/interpreter built with Flex and Bison for the compiler lab rubric.
The goal is to help students understand how lexical analysis, parsing, and simple execution work without turning the project into a full compiler.

## What it supports

- Lexical analysis with invalid-token reporting and line numbers
- Syntax analysis with Bison
- Variables with 4 data types
  - `_x` style int declaration
  - `_.pi` style float declaration
  - `__name` style string declaration
  - `___ok` style bool declaration
- Arithmetic, relational, and logical expressions
- `when`, `otherwise when`, `otherwise`
- `loop (condition)` style loop
- `loop (init; condition; update)` style loop
- `function`, parameters, function calls, and `reply`
- `stop` and `moveon` inside loops
- `show()` and `take()`
- Semantic checks
  - use before declaration
  - redeclaration
  - wrong type assignment
  - undefined function
  - wrong number of function arguments

## Beginner limits

- Function definitions must stay at the top level
- Variables are either global or local to the current function
- Nested loops are intentionally rejected to keep execution logic easy to follow
- The project focuses on the main compiler ideas, not on covering every advanced language feature

## Important syntax note

This compiler accepts the common lab-style form where declaration uses the prefixed name:

```txt
_x = 5;
_.pi = 3.14;
__name = "Compiler";
___ready = true;
```

After declaration, you can use either the normalized name or the prefixed name:

```txt
x = x + 1;
show(x);
show(_x);
```

For consistency, it is easier to:

1. Declare with the prefix.
2. Use the plain normalized name afterwards.

## Build

```bash
flex lexer.l && bison -d parser.y && gcc lex.yy.c parser.tab.c parser_runtime.c -o compiler -lm
```

## Run

```bash
./compiler
```

Then choose:

- `1` to type code directly
- `2` to read a source file and save results to `output.txt`

## Test files

Feature-based sample programs are inside `tests/`.
