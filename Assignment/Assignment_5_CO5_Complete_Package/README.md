# Assignment 5 – CO5: Reliable Software with Runtime Polymorphism and Exceptions

**Student:** Nitish RP  
**Register Number:** [Enter your register number]  
**Repository name required by assignment:** `DSA01-<RegisterNumber>-Assignment5`  
**Compiler used for package verification:** g++ (see `EXECUTION_REPORT.txt`)  
**Standard:** C++17

## Folder structure
- `Task01` – A1 polymorphic bill hierarchy
- `Task02` – A2 runtime binding, vtable model and destructor experiment
- `Task03` – A3 abstract payer classes and extension
- `Task04` – A4 exception hierarchy and strategy
- `Task05` – A5 recovery, rethrowing and RAII
- `Task06` – B1 completed TODO program and validation
- `Task07` – B2 engineered error conditions and completed TODOs
- `Task08` – B3 virtual/switch/variant and exception benchmarks
- `Task09` – B4 new bill and payer extensions
- `EXECUTION_REPORT.txt` – compile/run records
- `SANITIZER_REPORT.txt` – AddressSanitizer attempts/results

## Compile and run
For ordinary programs:
```bash
g++ -std=c++17 -Wall -Wextra Task01/polymorphic_hierarchy.cpp -o task01
./task01
```
For the benchmark:
```bash
g++ -std=c++17 -O2 -Wall -Wextra Task08/b3_benchmark.cpp -o benchmark
./benchmark
```
For AddressSanitizer:
```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer Task06/b1_complete_code.cpp -o task_asan
./task_asan
```

## Task-wise result
1. A1: Four concrete bill types share the abstract Bill interface.
2. A2: Late binding, conceptual vtables and virtual destructor behavior are demonstrated.
3. A3: SelfPay, Insurance, GovernmentScheme and CorporateTieUp implement Payer.
4. A4: Domain exception hierarchy, validation and rethrowing are demonstrated.
5. A5: Destructor order during stack unwinding confirms RAII cleanup.
6. B1: Completed TODOs produce OP Ravi 1700, IP Meena 47500 and Total 49200.
7. B2: Negative/oversized inputs and claim errors are handled; allocation failure behavior is reported as observed.
8. B3: Dispatch and exception benchmarks are recorded in `Task08/benchmark_results.txt`.
9. B4: TelemedicineBill and EmployeeBenefit extend the interfaces without changing existing concrete classes.

## Important submission checklist
- Replace the register-number placeholder and add the working GitHub URL to each Word document.
- Create the required repository and commit each task progressively (at least one commit per task).
- Capture screenshots of your own compile/run and sanitizer results. The report included here is reproducible evidence from the package build environment, not a substitute for screenshots requested from your own machine.
- The non-virtual base-destructor experiment is intentionally undefined behavior. Do not rely on one observed output as guaranteed.
- The assignment's required ASan experiment for the non-virtual destructor must be run locally; record the actual diagnostic. Do not claim a clean result for intentionally invalid code.
- B3 timings depend on machine/compiler/load. Repeat at least five times on your machine for stronger evidence.
