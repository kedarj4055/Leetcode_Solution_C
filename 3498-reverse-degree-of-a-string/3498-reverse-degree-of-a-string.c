int reverseDegree(char* s) {
    int sum=0,i,val;
    for(i=0;s[i]!='\0';i++){
        val=26-(s[i]-'a');
        sum+=val*(i+1);
    }
    return sum;
}