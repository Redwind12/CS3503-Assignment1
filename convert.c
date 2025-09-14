#include "convert.h"
#include <string.h>
#include <stdio.h>   // optional for debugging
#include <stdint.h>

static void reverse_in_place(char *s) {
    size_t i = 0, j = strlen(s);
    if (j == 0) return;
    j--;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

void div_convert(uint32_t n, int base, char *out) {
    char temp[65];
    int pos = 0;

    if (n == 0) {
        out[0] = '0';
        out[1] = '\0';
        return;
    }

    while (n > 0) {
        int rem = (int)(n % (uint32_t)base);
        n /= (uint32_t)base;

        if (rem < 10)
            temp[pos++] = (char)('0' + rem);
        else
            temp[pos++] = (char)('A' + (rem - 10));
    }

    temp[pos] = '\0';
    reverse_in_place(temp);
    strcpy(out, temp);
}
#include "convert.h"
#include <stdio.h>   // for printf

void print_tables(uint32_t n) {
    char bin[65];
    char oct[65];
    char hex[65];

    // --- Original value ---
    div_convert(n, 2, bin);
    div_convert(n, 8, oct);
    div_convert(n, 16, hex);
    printf("Original: Binary=%s Octal=%s Decimal=%u Hex=%s\n",
           bin, oct, n, hex);

    // --- Left shift by 3 ---
    uint32_t shifted = n << 3;
    div_convert(shifted, 2, bin);
    div_convert(shifted, 8, oct);
    div_convert(shifted, 16, hex);
    printf("Left Shift by 3: Binary=%s Octal=%s Decimal=%u Hex=%s\n",
           bin, oct, shifted, hex);

    // --- AND with 0xFF ---
    uint32_t masked = n & 0xFF;
    div_convert(masked, 2, bin);
    div_convert(masked, 8, oct);
    div_convert(masked, 16, hex);
    printf("AND with 0xFF: Binary=%s Octal=%s Decimal=%u Hex=%s\n",
           bin, oct, masked, hex);
}
void sub_convert(uint32_t n, int base, char *out) {
    if (base < 2 || base > 16) { out[0] = 'E'; out[1] = 'R'; out[2] = 'R'; out[3] = '\0'; return; }
    if (n == 0) { out[0] = '0'; out[1] = '\0'; return; }

    // Find largest power of base <= n without overflowing:
    uint32_t power = 1;
    while (power <= n / (uint32_t)base) {   // ✅ no overflow
        power *= (uint32_t)base;
    }

    char temp[65];
    int pos = 0;

    while (power > 0) {
        int digit = (int)(n / power);
        n -= (uint32_t)digit * power;
        power /= (uint32_t)base;

        temp[pos++] = (digit < 10) ? (char)('0' + digit)
                                   : (char)('A' + (digit - 10));
    }
    temp[pos] = '\0';
    strcpy(out, temp);
}



