/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* c, int cs, int ec, int* rs) {
    int i,max=c[0];
    bool *ans=malloc(cs*sizeof(bool));
    *rs=cs;
    for(i=1;i<cs;i++){
        if(c[i]>max)
        max=c[i];
    }
    for(i=0;i<cs;i++){
        if(c[i]+ec>=max)
        ans[i]=true;
        else
        ans[i]=false;
    }
    return ans;
}