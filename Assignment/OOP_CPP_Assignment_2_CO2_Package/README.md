# OOP with C++ – Assignment 2 (CO2)

## Student details
- Name: [Enter your full name]
- Register Number: [Enter your register number]
- GitHub repository: `DSA01-<RegisterNumber>-Assignment2`
- Compiler: g++ (Debian 14.2.0-19) 14.2.0
- Language standard: C++17

## Compile command
For each normal task program:
```bash
g++ -std=c++17 -Wall -Wextra TaskXX/QX.cpp -o task
```
Run on Linux/macOS:
```bash
./task
```
On Windows MinGW:
```bash
task.exe
```

## Folder contents
- `Task01` to `Task07`: separate task folder, report and source file(s).
- `EXECUTION_REPORT.txt`: observed program outputs and compiler information.
- `README.md`: repository setup and task summaries.

## Task summaries
1. **Q1 – Call by value, reference and pointer:** demonstrates caller state, return by reference, default arguments, and concession update.
2. **Q2 – Return by reference:** modifies the highest array element through a reference; compares const reference, copy, index and pointer. The dangling-reference function is compiled only to inspect the warning and is never called.
3. **Q3 – Default arguments and overloading:** avoids ambiguity by separating grams (`int`), kilograms (`double`) and `Parcel` inputs.
4. **Q4 – Array inside a class:** stores the most recent ten transactions using a circular index, avoiding shifts when full.
5. **Q5 – Static members and arrays of objects:** uses a shared static ticket counter and demonstrates capacity/waiting-list behaviour.
6. **Q6 – Friend and inline functions:** compares two `Time` objects using private data and includes an inline timing experiment.
7. **Q7 – Diagnose, redesign and validate:** selects Q4's shifting history as the original limitation and validates a circular-buffer redesign.

## Important assumptions and notes
- Monetary amounts in Q4 are represented as integer paise to avoid floating-point rounding.
- Q4 retains the newest ten transactions. The circular-buffer index is used so insertion after the buffer fills is O(1).
- Q5's ticket capacity is three, matching the supplied TODO example.
- Q6's benchmark timings are machine/compiler dependent. Re-run on your own computer and replace the sample timings with your own evidence.
- Q7 compares shifting and circular insertion using the same capacity and operation count. Timings vary by hardware and compiler; the asymptotic result is O(k) versus O(1) per insertion after the history fills.
- Q2's dangling-reference function is intentionally not called. Dereferencing its result would be undefined behaviour.

## GitHub submission checklist
1. Replace the name and register-number placeholders.
2. Run every `.cpp` file on your own computer and save screenshots of the terminal output in the corresponding task folder.
3. Add your screenshots and any required input/output files.
4. Create the repository with the exact name `DSA01-<RegisterNumber>-Assignment2`.
5. Commit progressively, with at least one commit per task (do not upload everything in one final commit).
6. Add the course faculty as collaborator if the repository is private.
7. Paste the working GitHub repository URL into the assignment cover page and submission field.
