int lengthOfLastWord(char* s) {
    int i=0,count=0;
    while(s[i]!='\0'){
        i++;
    }
    i--;
    while(i>=0&&s[i]==' '){
    i--;
    }
    while(i>=0&&s[i]!=' '){
        count++;
    i--;
    }
    return count;
}