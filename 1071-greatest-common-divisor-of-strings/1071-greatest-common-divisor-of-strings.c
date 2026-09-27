char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    int totalLen = len1 + len2;
    char* concat1 = (char*)malloc(totalLen + 1);
    char* concat2 = (char*)malloc(totalLen + 1);
    strcpy(concat1, str1);
    strcat(concat1, str2);
    strcpy(concat2, str2);
    strcat(concat2, str1);
    int equal = (strcmp(concat1, concat2) == 0);
    free(concat1);
    free(concat2);
    static char res[1001];
    if (!equal) {
        res[0] = '\0';
        return res;
    }
    int a = len1, b = len2, temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    strncpy(res, str1, a);
    res[a] = '\0';
    return res;
}