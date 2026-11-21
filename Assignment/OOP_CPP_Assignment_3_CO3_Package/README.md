# OOP with C++ – Assignment 3 (CO3)

## Student details
- Name: [Enter full name]
- Register Number: [Enter register number]
- Repository: `DSA01-<RegisterNumber>-Assignment3`
- Compiler used for preparation: g++ (Debian 14.2.0-19) 14.2.0
- Standard: C++17

## Compile and run
Example:
```bash
g++ -std=c++17 -Wall -Wextra Task01/Q1.cpp -o task01
./task01
```
For AddressSanitizer:
```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer Task02/Q2.cpp -o q2_asan
./q2_asan
```
For optimisation experiments, compile with `-O0` and `-O2`.

## Contents
- Task01–Task07: one folder per assignment question.
- Each task folder contains a solved Word document and its C++ source file(s).
- Supporting experiment sources are included where needed.
- `EXECUTION_REPORT.txt` records compile/run outputs and environment limitations.
- `README.md` gives setup and submission instructions.

## Task summary
1. Constructors, delegation, initializer lists, validation and explicit.
2. Deep copy, assignment, destructor, Rule of Three, Rule of Zero comparison.
3. Dynamic 2D allocation, destructor, RAII, stack/heap/block lifetimes.
4. Money arithmetic and stream operator overloads.
5. Prefix/postfix increment, comparisons and checked playlist subscript.
6. Text class, Rule of Three, operator-overloading rules and concatenation.
7. Complex-number class for series/parallel impedance and safe division.

## Important execution notes
- Q2/Q3/Q6 sanitizer builds were attempted, but this environment's ASan runtime failed to initialise (`ASan runtime does not come first in initial library list`). This is an environment/runtime limitation, not a successful sanitizer result. Re-run locally or use Valgrind and capture the actual report.
- Q5 benchmark timings are compiler/hardware dependent. Re-run at both `-O0` and `-O2`.
- Q6 repeated concatenation and Q4 double-vs-integer experiment should be timed locally for credible hardware-specific measurements.
- Q1's `constructor_experiments.cpp` includes a deliberately wrong initializer-list order to demonstrate `-Wreorder`; it also comments out the array declaration that should fail due to the absence of a default constructor.
- Unsafe shallow-copy behaviour is explained in Q2 but is not executed as a crashing target; run such intentionally unsafe code only in a disposable sanitizer test environment.

## GitHub submission checklist
1. Replace name/register placeholders in README and every Word document.
2. Create repository exactly as `DSA01-<RegisterNumber>-Assignment3`.
3. Upload the extracted Task01–Task07 folders and README.
4. Run each program on your own computer and save terminal screenshots inside its task folder.
5. Run sanitizer and timing experiments locally; add actual reports and measurements.
6. Commit progressively, with at least one commit per task.
7. If private, add course faculty as collaborator.
8. Paste the working GitHub URL on the report cover and submission field.
