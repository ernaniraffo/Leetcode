void reverseString(char* s, int sSize) {
    char* end = s + (sSize - 1);
    if (s) {
        while (s < end) {
            *s ^= *end;
            *end ^= *s;
            *s ^= *end;
            s++;
            end--;
        }
    }
}
