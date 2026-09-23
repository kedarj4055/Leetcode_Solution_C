

char * mergeAlternately(char * word1, char * word2){
        int i = 0, j = 0, k = 0;
    char* result = malloc(strlen(word1) + strlen(word2) + 1);
    while (word1[i] != '\0' || word2[j] != '\0') {
        if (word1[i] != '\0') {
            result[k] = word1[i];
            i++;
            k++;
        }
        if (word2[j] != '\0') {
            result[k] = word2[j];
            j++;
            k++;
        }
    }
    result[k] = '\0';
    return result;
}