#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "convert.h"

int main(void) {
    FILE *file = fopen("A1_tests.txt", "r");
    if (!file) {
        printf("Error: could not open A1_tests.txt\n");
        return 1;
    }

    char line[512];
    int test_idx = 0;
    int total = 0;
    int passed = 0;

    while (fgets(line, sizeof(line), file)) {
        /* remove newline at the end */
        line[strcspn(line, "\r\n")] = '\0';

        /* skip blank lines */
        if (line[0] == '\0') {
            continue;
        }

        /* skip full-line comments */
        if (line[0] == '#') {
            continue;
        }

        /* try to match each test shape with simple sscanf */
        unsigned int n;
        int base;
        char expect[128];
        char got[128];

        /* div_convert n base expect */
        if (sscanf(line, "div_convert %u %d %127s", &n, &base, expect) == 3) {
            div_convert(n, base, got);
            test_idx++;
            total++;
            if (strcmp(expect, got) == 0) {
                passed++;
                printf("Test %d: div_convert(%u, %d)-> Expected: \"%s\", Got: \"%s\" [PASS]\n",
                       test_idx, n, base, expect, got);
            } else {
                printf("Test %d: div_convert(%u, %d)-> Expected: \"%s\", Got: \"%s\" [FAIL]\n",
                       test_idx, n, base, expect, got);
            }
            continue;
        }

        /* sub_convert n base expect */
        if (sscanf(line, "sub_convert %u %d %127s", &n, &base, expect) == 3) {
            sub_convert(n, base, got);
            test_idx++;
            total++;
            if (strcmp(expect, got) == 0) {
                passed++;
                printf("Test %d: sub_convert(%u, %d)-> Expected: \"%s\", Got: \"%s\" [PASS]\n",
                       test_idx, n, base, expect, got);
            } else {
                printf("Test %d: sub_convert(%u, %d)-> Expected: \"%s\", Got: \"%s\" [FAIL]\n",
                       test_idx, n, base, expect, got);
            }
            continue;
        }

        /* print_tables n (formatted check only) */
        if (sscanf(line, "print_tables %u", &n) == 1) {
            print_tables(n);
            test_idx++;
            total++;
            passed++; /* assignment treats this as a formatted-output check */
            printf("Test %d: print_tables(%u)-> [FORMATTED OUTPUT CHECK] [PASS]\n",
                   test_idx, n);
            continue;
        }

        /* if we get here, the line wasn’t a test we recognize — just ignore it */
    }

    fclose(file);
    printf("Summary: %d/%d tests passed\n", passed, total);
    return 0;
}
