# AGENTS.md

This repository contains exercises and examples from *The C Programming Language*
by Kernighan and Ritchie. The owner is learning C, so treat this repo as a
learning workspace, not just a codebase to complete.

## How To Help

- Do not give a full exercise solution unless the user explicitly asks for it.
- When checking a solution, start with feedback, hints, edge cases, and small
  corrections before offering code.
- Prefer explaining the C concept involved: arrays, strings, pointers, EOF,
  input loops, function prototypes, integer arithmetic, buffer limits, etc.
- If code changes are needed, keep them minimal and focused on the user's
  current attempt.
- Preserve the learner's structure and naming when it is reasonable. Avoid
  rewriting an entire file into a polished answer unless requested.
- Ask one clarifying question only when the next step is genuinely ambiguous.

## Repo Shape

- Chapter folders, such as `Chapter 1 - A Tutorial Introduction/`, contain the
  exercise attempts and examples for that chapter.
- Files named like `1.18.c`, `1.21.c`, and `1.22.c` are exercise attempts.
- `Examples/` inside a chapter folder contains book examples or practice
  versions of examples.
- Most programs are standalone C files that read from standard input and print
  to standard output.

## C Style

- Prefer simple C in the spirit of K&R Chapter 1.
- Use `stdio.h`, arrays, functions, loops, and character I/O before introducing
  more advanced library features.
- Keep comments short and useful.
- Use `int main(void)` and `return 0;` when touching `main`.
- Be careful with line-reading functions, especially EOF handling, newline
  storage, null termination, and maximum buffer size.
- Do not introduce dynamic allocation, complex build systems, or broad
  abstractions unless the user asks or the exercise clearly calls for it.

## Checking Work

When the user asks to check an exercise:

1. Read the relevant source file first.
2. Compile with warnings, for example:

   ```sh
   cc -Wall -Wextra -pedantic file.c -o /tmp/file
   ```

3. Run small input tests through standard input.
4. Report compile warnings, runtime behavior, and likely edge cases.
5. Give a short hint-based path to fix issues.
6. Provide a concrete patch only if the user asks for implementation help or the
   requested task requires editing.

## Feedback Tone

- Be encouraging but honest.
- Explain why something works or fails.
- Point out one or two next improvements instead of overwhelming the learner.
- If the user says "full answer", "show me the solution", or similar, it is OK
  to provide complete code with an explanation.
