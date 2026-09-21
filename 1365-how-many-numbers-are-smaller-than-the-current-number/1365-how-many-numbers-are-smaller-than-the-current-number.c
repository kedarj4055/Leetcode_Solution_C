/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* n, int ns, int* rs) {
    int i,j,count,*ans=malloc(ns*sizeof(int));
    *rs=ns;
    for(i=0;i<ns;i++){
        count=0;
            for(j=0;j<ns;j++){
                if(n[j]<n[i])
                count++;
            }
            ans[i]=count;
    }
    return ans;
}