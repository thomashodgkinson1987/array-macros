# AI Bootstrap Guide

## Execution Protocol

During the bootstrap sequence (Steps 1-7), I will minimise my output. I will only print the title of the step being executed (e.g., `# Step 1: Acknowledge Identity`). I will not provide a summary or confirmation after each step. I will only resume our normal conversational interaction upon reaching the final "Synthesise and Engage" step.

## Objective

This document contains the bootstrap instructions for a new AI session. Upon initialisation, I am to follow these steps sequentially to gain full context of the project and our ongoing collaboration.

## Bootstrap Sequence

1.  **Acknowledge Identity:** Read the contents of `/.tabernacle/AI-PERSONA.md` to understand my name, my role, personal directives, and our collaborative dynamic.

2.  **Acknowledge Developer Persona:** Read the contents of `/.tabernacle/DEVELOPER-PERSONA.md` to understand the developer's working style, goals, and known operational constraints.

3.  **Understand the Project:** Read the contents of `/.tabernacle/PROJECT-OVERVIEW.md` to get a high-level understanding of the project's goals, architecture, and conventions.

4.  **Review Project Conventions:** Read the contents of `STYLE-GUIDE.md` to internalise all established coding, Git, and documentation standards.

5.  **Review Kanban Boards:** Read the contents of the three Kanban board files, located in the `/.cubit/` directory, to understand the project's state:
    -   `/.cubit/KANBAN-CURRENT.md`: The single task that is currently in progress.
    -   `/.cubit/KANBAN-BACKLOG.md`: The list of tasks waiting to be worked on.
    -   `/.cubit/KANBAN-COMPLETED.md`: The history of all completed tasks.

6.  **Review Session Notes:** Read the contents of `/.tabernacle/NOTES.md` to get up to speed on any specific, notes.

7.  **Analyse Live Git State:** Execute the following Git commands to get a live, accurate understanding of the repository's current state:
    -   `git status`
    -   `git branch --all`
    -   `git log --graph --oneline --decorate --all -n 15`

8.  **Synthesise and Engage:** After completing the analysis, I will synthesise all information. My next action depends on whether a handoff document is available.
    -   **If a handoff file is found:** I will announce that a handoff was provided and immediately begin our session by reviewing its contents with you.
    -   **If no handoff file is found:** I will state that no handoff was provided and give a general project health summary based on the Git state and Kanban boards. I will then enter **Plan Mode**, and we can determine our next steps together.
