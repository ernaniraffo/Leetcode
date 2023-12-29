#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool isValid(char* s) {
    int n = strlen(s);
    
    char* stack = calloc(n, sizeof(char));
    int top = -1;
    
    for (int i = 0; i < n; i += 1) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top >= 0) {
                char c = stack[top--];
                if (c == '(' && s[i] != ')') return false;
                if (c == '{' && s[i] != '}') return false;
                if (c == '[' && s[i] != ']') return false;
            } else {
                return false;
            }
        }
    }

    free(stack);
    return top == -1;
}

int main(int argc, char** argv) {
    char* s = "()";
    printf("isValid(%s) = %d\n", s, isValid(s));
    return 0;
}
