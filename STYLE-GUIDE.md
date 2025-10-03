# Style Guide

This document is the single source of truth for all coding, documentation, and workflow conventions.

## 1. General Principles

1.  **Clarity Over Cleverness:** Code should be written to be read.
2.  **Consistency is Key:** When in doubt, find a similar piece of code and follow its pattern.
3.  **Document the "Why," Not the "What":** The code explains *what* it's doing; comments and commit messages should explain *why*.

## 2. Language & Terminology

-   **Prose (Documentation, Comments):** British English (`colour`, `behaviour`).
-   **Code (Variables, Functions, APIs):** US English (`color`, `behavior`).
-   **Official Spellings:** The following terms should always be written as a single word:
    -   `codebase`
    -   `workflow`
    -   `filename`
    -   `submodule`
    -   `handoff`
    -   `backlog`

## 3. C Language Conventions

### 3.1. Formatting

-   **Column Limit:** All C code is strictly limited to **80 columns**.
-   **Brace Style:** Use the **Allman style**, where the brace for a control statement (`if`, `else`, `for`, `while`) or function definition is always placed on a new line.
-   **Pointers:** The asterisk aligns with the variable name: `char *buffer`.

### 3.2. Naming

-   **Code Files (`.c`, `.h`):** `snake_case` (e.g., `command_system.h`).
-   **Documentation & Metadata:** `dash-case` (e.g., `PROJECT-OVERVIEW.md`).
-   **Functions & Variables:** `snake_case` (e.g., `command_system_create`).
-   **Enums:** `SCREAMING_SNAKE_CASE` with a `_TYPE` suffix for the enum name and a `_NONE` member for the zero value (e.g., `COMMAND_TYPE_NONE`).

### 3.3. Headers (`.h`)

-   **Include Guards:** Use `#ifndef PROJECT_MODULE_H` format (e.g., `CHIMERA_ENGINE_COMMAND_SYSTEM_H`).
-   **Include Order:** Includes must be sorted alphabetically within the following groups, separated by a blank line:
    1.  The primary header for the corresponding `.c` file (`"command_system.h"`).
    2.  System headers (`<stdbool.h>`, `<stdlib.h>`).
    3.  Library headers (`<queue_macros.h>`).
    4.  Project headers (`"actor.h"`, `"world.h"`).

### 3.4. API Design

-   **`const`-Correctness:** Strive for `const`-correctness wherever possible. Provide `_mut` variants for getter functions where mutable access is required.
-   **Explicit Context:** Avoid singletons. Pass necessary context (e.g., `World *`, `Game *`) as explicit function arguments.
-   **Opaque Pointers:** Core systems should be encapsulated behind opaque pointers (handles) to hide implementation details.

### 3.5. Memory Management

-   **Ownership:** Ownership is clear and encapsulated. `_create` functions `malloc` memory, and corresponding `_free` functions `free` it. The calling code does not manage memory for objects it receives.
-   **Null Checks:** Do not perform a null check before calling `free()`.

## 4. Git & Version Control

### 4.1. Branching Workflow

-   Branch prefixes should align with the Conventional Commit type of the work (e.g., `feature/`, `refactor/`, `fix/`, `chore/`). All work is done on these branches, which are created from `develop`.
-   Feature branches are **squash merged** into `develop`.
-   `develop` is merged into `main` for releases using `--no-ff`.

### 4.2. Commit Messages

All commit messages must adhere to the **Conventional Commits** specification.

-   **Structure:** `type(scope): Subject`
-   **Mood:** The subject line must be written in the **imperative mood** ("Add feature," not "Added feature" or "Adds feature").
-   **Capitalisation:** The subject line begins with a capital letter.
-   **Length:** The subject line should not exceed **50 characters**. This is a strong guideline, not a hard rule; clarity is more important than brevity. The body, if present, should be wrapped at **72 characters**.
-   **Scopes:**
    -   Use a short, descriptive noun for the part of the codebase affected.
    -   Examples: `game`, `actor`, `cmdsys`, `input`, `build`.
    -   For project-wide changes, use `project`, `workflow`, `deps`, or `plan`.

**Example Commit:**
```
refactor(project): Adapt codebase to queue-macros handler API

Refactors the `CommandSystem` and `InputSystem` to integrate the
updated `queue-macros` submodule, which now uses an opaque pointer
and a new function signature pattern.

- All calls to the queue API are updated to pass the queue by pointer.
- Logic is updated to handle new boolean return types and `out`
  parameters, improving error handling.
```
