# OOP with C++ – Assignment 4 (CO4): Designing Reusable Class Hierarchies

## Student details
- Name: [Enter full name]
- Register Number: [Enter register number]
- GitHub repository: `DSA01-<RegisterNumber>-Assignment4`
- Compiler used: g++ (Debian 14.2.0-19) 14.2.0
- Standard: C++17

## Compile and run
```bash
g++ -std=c++17 -Wall -Wextra Task01/Q1.cpp -o task01
./task01
```
Repeat for each source file. On Windows MinGW run `task01.exe`.

## Contents
- Task01 through Task06: separate folders.
- Each folder includes `<TaskXX>_Solved.docx`, C++ source, and execution evidence.
- Supporting experiments include non-virtual diamond, constructor-order prediction and virtual dispatch prediction.
- `EXECUTION_REPORT.txt` contains compilation and observed outputs.

## Task summary
1. Diagnose duplicated payroll classes and repair with a polymorphic Staff hierarchy.
2. Design Person/Student/Staff/TeachingAssistant/ResearchScholar and solve the diamond using virtual inheritance.
3. Implement derived and member-class constructors; trace object construction/destruction.
4. Repair polymorphic Account pointers, virtual dispatch, virtual destruction and slicing.
5. Use objects, pointers, references, dynamic allocation and this-pointer chaining in Cart.
6. Design an extensible vehicle-rental hierarchy and add ElectricBus without modifying existing vehicle classes.

## Assumptions
- Task 1 uses a 42% DA rate because that is the rate in the supplied example; the unused `da` field is removed.
- Task 6 uses illustrative daily charges and a late-return multiplier of 1.5 because the assignment does not specify numeric pricing rules.
- Exact sizeof values depend on compiler, ABI and platform.
- The unsafe original Task 4 example is diagnosed but not run as a normal program because deleting a derived object through a non-virtual base destructor is undefined behaviour.

## GitHub submission checklist
1. Replace name and register-number placeholders in README and every Word document.
2. Create repository `DSA01-<RegisterNumber>-Assignment4`.
3. Upload the extracted Task01–Task06 folders and README.
4. Execute all programs on your computer and save terminal screenshots in the correct task folders.
5. Capture local evidence for the non-virtual diamond, `-Wreorder`, and sanitizer investigation if required.
6. Commit progressively with at least one commit per task.
7. If private, add the course faculty as collaborator.
8. Paste the working GitHub URL on the report cover and submission field.
