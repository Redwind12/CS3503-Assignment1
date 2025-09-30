# CS3503 Assignment 1 & 2 – Advanced Data Representation

## Build Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/Redwind12/CS3503-Assignment1.git
   cd CS3503-Assignment1
   ```
2. Open the project in CLion (or any C IDE that supports CMake).
3. Build the project.
4. Run the program.

    * By default it looks for `A2_tests.txt`.
    * If that file is not found, it falls back to `A1_tests.txt`.

---

## Files Included

* `main.c` – test runner (reads test file, executes functions, prints PASS/FAIL).
* `convert.c` – implementations of conversion functions (A1 + A2).
* `convert.h` – header file with function prototypes.
* `A1_tests.txt` – test cases for Assignment 1.
* `A2_tests.txt` – test cases for Assignment 2.
* `CMakeLists.txt` – build configuration.
* `README.md` – build + run instructions.

---

## Running Tests

### Assignment 2

1. Ensure `A2_tests.txt` is in the project root.
2. Build & run the program.
3. Example output format:

   ```
   Test 1: oct_to_bin("725")-> Expected: "111010101", Got: "111010101" [PASS]
   Test 2: to_twos_complement(-5)-> Expected: "11111111111111111111111111111011",
           Got: "11111111111111111111111111111011" [PASS]
   ...
   Summary: 60/60 tests passed
   ```

### Assignment 1

1. Either remove/rename `A2_tests.txt` so the program falls back to `A1_tests.txt`,
   or edit `main.c` to open `A1_tests.txt` directly.
2. Build & run.
3. Example output format:

   ```
   Test 1: div_convert(104, 5)-> Expected: "404", Got: "404" [PASS]
   Test 2: sub_convert(255, 16)-> Expected: "FF", Got: "FF" [PASS]
   Test 3: print_tables(5)-> [FORMATTED OUTPUT CHECK] [PASS]
   ...
   Summary: 145/147 tests passed
   ```

---

## Notes

* The program reads test cases line by line from the input file.
* Each test prints whether it PASSED or FAILED, followed by a summary.
* `print_tables` tests are always marked `[FORMATTED OUTPUT CHECK] [PASS]` since correctness depends on manual formatting.

---

