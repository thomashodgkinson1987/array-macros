# Handoff Template And Guidance

*Use this template to generate consistent, actionable handoff reports for development sessions.*

**When generating a handoff report:**

1. **Replace all bracketed placeholders** with session-specific information
2. **Focus on actionability** - ensure next session can start immediately with clear direction
3. **Prioritise technical continuity** - include enough context to resume implementation work
4. **Be specific about file locations** - mention exact files, functions, branches involved
5. **Highlight architectural decisions** - capture reasoning behind design choices
6. **Use consistent formatting** - maintain professional tone suitable for project documentation

**Section Guidelines:**
- **Executive Summary:** Focus on business/project impact, not just technical activities
- **Key Discoveries:** Include both problems found and solutions designed
- **Deliverables:** Be specific about what can be immediately used/implemented
- **Technical Context:** Provide enough detail for seamless resumption without re-analysis
- **Next Priorities:** Order by dependency and impact, not just importance

**Quality Check:**
Ask yourself: "Could someone else (or future me) read this and immediately continue the work effectively?"

---

# Development Session Handoff

*Project: [PROJECT NAME]*
*Session Date: [DD-MM-YYYY]*
*Developer: [DEVELOPER NAME]*
*AI Assistant: [AI NAME]*

---

## Executive Summary

[2-3 sentence overview of the session's primary focus and key outcomes]

## Current Project State

### Git Status

- **Current Branch:** `[BRANCH_NAME]`
- **Branch State:** [up to date/ahead/behind] with origin, [clean/dirty] working tree
- **Last Commit:** [COMMIT_MESSAGE] ([COMMIT_HASH])

### Active Task Status

- **Current Task:** [TASK_NAME from KANBAN_CURRENT.md]
- **Progress:** [Percentage or action items completed]
- **Status:** [on track/blocked/completed/needs attention]

## Session Activities

### [Major Activity 1 - e.g., "Implementation Work", "Architecture Discussion", "Bug Investigation"]

[Description of what was accomplished, decisions made, code written, etc.]

### [Major Activity 2 - if applicable]

[Description]

### [Major Activity N - if applicable]

[Description]

## Key Discoveries & Decisions

### [Discovery/Decision 1 Title]

**Issue:** [What problem was identified]
**Analysis:** [Technical analysis or reasoning]
**Decision:** [What was decided/designed]
**Impact:** [How this affects the project going forward]

### [Additional discoveries as needed]

## Blockers & Issues Identified

### [Blocker Title - if any]

**Problem:** [Description of the blocking issue]
**Impact:** [How it affects progress]
**Proposed Solution:** [Recommended approach to resolve]

*[If no blockers: "No blocking issues identified this session."]*

## Deliverables Created

### [Deliverable Type - e.g., "Task Documentation", "Code Artefacts", "Design Documents"]
- [Specific item 1]: [Brief description and location/status]
- [Specific item 2]: [Brief description and location/status]

### [Additional deliverable categories as needed]

## Next Session Priorities

### Immediate Actions (High Priority)
1. **[Action Item]:** [Description and expected outcome]
2. **[Action Item]:** [Description and expected outcome]

### Follow-up Items (Medium Priority)
- [Item]: [Description]
- [Item]: [Description]

### Future Considerations (Low Priority)
- [Item]: [Description]
- [Item]: [Description]

## Technical Context for Resumption

### Current Implementation State
[Brief technical summary of where code/implementation stands, what files are involved, what's partially complete]

### Key Variables/State to Remember
- [Important context item 1]
- [Important context item 2]

### Recommended Approach for Next Session
[Suggested starting point and approach for continuing the work]

## Development Workflow Status

**Kanban Board Status:**
- Current: [Number of items]
- Backlog: [Number of items] 
- Recently Completed: [Any items moved during session]

**Git Hygiene:** [Assessment of branch state, commit history, any cleanup needed]

**Project Health:** [Overall assessment - good/needs attention/critical issues]
