#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

bool isPalindrome(char* s) {
    int l = 0;
    int r = strlen(s) - 1;
    
    while (l < r) {
        while (l < r && !isalnum(s[l])) {
            l++;
        }
        while (l < r && !isalnum(s[r])) {
            r--;
        }
        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        l++;
        r--;
    }
    
    return true;
}

int main(int argc, char** argv) {
    char* s = "racecar";
    printf("%s %s a palindrome\n", s, (isPalindrome(s) ? "is" : "is not"));
    return 0;
}