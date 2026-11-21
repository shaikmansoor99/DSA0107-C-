# Assignment 1 – City Metro Smart-Card Fare Logic

## Student details
- Name: [ENTER FULL NAME]
- Register number: [ENTER REGISTER NUMBER]
- Course: Object Oriented Programming with C++
- CO: CO1
- Required repository name: `DSA01-<RegisterNumber>-Assignment1`
- GitHub URL: [ADD AFTER CREATING THE REPOSITORY]

## Compiler and command
- Compiler detected during preparation: `g++ (Debian 14.2.0-19) 14.2.0`
- C++ standard: C++17
- Exact compilation command used: `g++ -std=c++17 -Wall -Wextra taskXX.cpp -o taskXX`
- Run (Linux/macOS): `./taskXX`
- Run (Windows PowerShell): `./taskXX.exe`

Example:
```bash
cd Task06
g++ -std=c++17 -Wall -Wextra task06.cpp -o task06
./task06
```

## Folder structure
- `Task01/` – Task 1 separate Word solution
- `Task02/` – Task 2 separate Word solution
- `Task03/` – Task 3 separate Word solution
- `Task04/` – Task 4 separate Word solution
- `Task05/` – Task 5 separate Word solution
- `Task06/` – Task 6 separate Word solution and runnable C++ source (`task06.cpp`)
- `Task07/` – Task 7 separate Word solution and runnable C++ source (`task07.cpp`)
- `Task08/` – Task 8 separate Word solution and runnable C++ source (`task08.cpp`)
- `Task09/` – Task 9 separate Word solution and runnable C++ source (`task09.cpp`)
- `Task10/` – Task 10 separate Word solution
- `Task11/` – Task 11 separate Word solution
- `Task12/` – Task 12 separate Word solution and runnable C++ source (`task12.cpp`)
- `EXECUTION_REPORT.txt` – compilation and run summary for supplied C++ programs.

## Task summary
1. Object-oriented analysis of SmartCard, Passenger, Journey, Zone and FareTable; procedural comparison, OOP principles and invariants.
2. Token categories, naming conventions, constexpr, const, #define and enum class.
3. Data type table, integer-paise justification, type compatibility, ranges and network overflow.
4. Prediction and explanation of implicit conversions; explicit casts and brace initialization.
5. Operator precedence, peak expressions, increment operators, signed division and remainder.
6. Structured pseudocode and completed switch-based fare logic.
7. Procedural and SmartCard OOP implementations, with balance invariant comparison.
8. Safe cin recovery, output formatting and getline/stoi alternative.
9. Fare test matrix, boundary cases, invalid zone, minimum balance and hand-calculated total.
10. Scale totals, integer overflow analysis, double versus integer paise and accumulator choices.
11. Final design recommendation, limitations and configuration-file alternative.
12. Design challenge: Airport zone, weekend discount and two-zone monthly pass.

## Policy assumptions and missing details
1. Peak intervals are interpreted as `[08:00, 10:00)` and `[17:00, 20:00)`: 08:00 and 17:00 are peak; 10:00 and 20:00 are off-peak.
2. Student/senior concession is mentioned, but the assignment does not state its percentage or whether it combines with peak surcharge. No rate has been invented. Confirm the official policy with the faculty/metro authority.
3. The weekend discount is applied to the base fare and does not combine with peak surcharge, as stated in Task 12.
4. The monthly pass is interpreted as covering journeys whose farthest zone is one of the two selected zones. The assignment does not specify transfer, route or expiry rules.
5. The ₹50 remaining-balance requirement is applied to stored-value deductions. Covered pass journeys do not deduct stored value.

## Execution status
- Task 6: **PASS** using the compiler above.
- Task 7: **PASS** using the compiler above.
- Task 8: **PASS** using valid input and invalid-input recovery tests.
- Task 9: **PASS** using the compiler above.
- Task 12: **PASS** using the compiler above.

## Before GitHub submission
- [ ] Enter your full name and register number in this README and each Word document.
- [ ] Create repository `DSA01-<RegisterNumber>-Assignment1`.
- [ ] Upload all Task folders and this README.
- [ ] Run the source files on your own machine and verify the compiler version.
- [ ] Add terminal screenshots and any input files required by your faculty to the corresponding task folder.
- [ ] Commit progressively, with at least one meaningful commit for every task.
- [ ] Add the faculty as collaborator if the repository is private.
- [ ] Add the working GitHub URL to your report cover page and submission.

**Important:** The assignment requires execution evidence and progressive Git commits. The provided execution logs document the supplied runnable examples, but you must personally verify them on your own system, capture screenshots, and create the required GitHub commit history. Do not claim a GitHub repository has been created until you create it and add the faculty.
