int lengthOfLongestSubstring(char* s) {
    int max = 0;
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        count = 1;
        for (int j = i + 1; s[j] != '\0'; j++) {
            int duplicate = 0;
            for (int k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    duplicate = 1;
                    break;
                }
            }
            if (duplicate)
                break;
            count++;
        }
        if (count > max)
            max = count;
    }
    return max;
}