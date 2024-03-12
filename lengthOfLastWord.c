int lengthOfLastWord(char* s) {
    int len = 0;
    bool matched = false;
    for (int c = strlen(s) - 1; c >= 0; c -= 1) {
        if (s[c] == ' ' && matched) {
            break;
        } else if (s[c] != ' ') {
            matched = true;
            len += 1;
        }
    }
    return len;
}
