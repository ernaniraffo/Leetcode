#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int s_size = strlen(s);
    int t_size = strlen(t);
    int i = 0;
    int j = 0;
    while (i < s_size && j < t_size) {
        if (s[i] == t[j]) {
            i += 1;
        }
        j += 1;
    }
    return i == s_size;
}