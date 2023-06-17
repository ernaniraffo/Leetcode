int strStr(char * haystack, char * needle){
    for (int i = 0; i < strlen(haystack); i += 1) {
        for (int j = 0; j < strlen(needle); j += 1) {
            if (haystack[i + j] != needle[j]) {
                break;
            } else if (j + 1 == strlen(needle)) {
                return i;
            }
        }
    }    
    return -1;
}
