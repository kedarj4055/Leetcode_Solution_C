char* removeOuterParentheses(char* s) {
    int count=0,i=0,j=0;
    while (s[i] != '\0') {
        if (s[i] == '(') {
            if (count > 0)
                s[j++] = s[i];
            count++;
        }
        else {
            count--;
            if (count > 0)
                s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
    return s;
}