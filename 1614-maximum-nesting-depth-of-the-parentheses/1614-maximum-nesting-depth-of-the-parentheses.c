int maxDepth(char* s) {
    int depth=0,max=0,i;
    for (i=0;s[i]!='\0';i++) {
        if (s[i] == '(') {
            depth++;
            if (depth > max) {
                max = depth;
            }
        }
        else if (s[i] == ')') {
            depth--;
        }
    }
    return max;
}