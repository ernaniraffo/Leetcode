int maxDepth(char* s) {
    int _maxDepth = 0;
    int depth = 0;
    while (*s != '\0') {
        if (*s == '(') {
            depth += 1;
        } else if (*s == ')') {
            _maxDepth = _maxDepth > depth ? _maxDepth : depth;
            depth -= 1;
        }
        s += 1;
    }
    return _maxDepth;
}
