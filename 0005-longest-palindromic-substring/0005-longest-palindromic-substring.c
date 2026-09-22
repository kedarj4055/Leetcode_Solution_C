char* longestPalindrome(char* s) {
    int left,right,i,start=0,n=strlen(s),maxlen=1;
    for(i=0;i<n;i++){
        left=right=i;
        while(left>=0&&right<n&&s[left]==s[right]){
            if(right-left+1>maxlen){
                start=left;
                maxlen=right-left+1;
            }
            left--;
            right++;
        }
        left=i;
        right=i+1;
        while(left>=0&&right<n&&s[left]==s[right]){
            if(right-left+1>maxlen){
            start=left;
            maxlen=right-left+1;
        }
        left--;
        right++;
    }
    }
    char *ans=malloc((maxlen+1)*sizeof(char));
    for(int i=0;i<maxlen;i++){
        ans[i]=s[start+i];
    }
    ans[maxlen]='\0';
    return ans;
}