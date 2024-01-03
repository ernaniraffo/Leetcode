#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int aP = strlen(a);
    int bP = strlen(b);
    int n = fmax(aP, bP);
    
    char* ans_str = calloc(n + 2, sizeof(char)); // n + 2 for null char and possible carry
    ans_str[n + 1] = '\0';
    for (int i = 0; i <= n; i += 1) {
        ans_str[i] = '0';
    }
    
    // decrement all lengths
    aP -= 1;
    bP -= 1;
    
    int carry = 0;
    
    while (aP >= 0 || bP >= 0 || n >= 0) {
        if (aP >= 0 && a[aP] == '1') {
            carry += 1;
        }
        if (bP >= 0 && b[bP] == '1') {
            carry += 1;
        }

        ans_str[n] = carry % 2 ? '1' : '0';
        n -= 1;
        aP -= 1;
        bP -= 1;
        carry /= 2;
    }

    if (ans_str[0] == '0') {
        memmove(ans_str, ans_str + 1, sizeof(char) * (strlen(ans_str)));
    }

    return ans_str;
}

int main(int argc, char** argv) {
    char* a = "100";
    char* b = "10";
    char* ans = addBinary(a, b);
    printf(" %s\n", a);
    printf("+%s\n", b);
    printf(" %s\n", ans);
    free(ans);
    return 0;
}
