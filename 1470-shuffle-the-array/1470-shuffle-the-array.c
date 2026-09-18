

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int ns, int n, int* rs){
    int *ans=malloc(ns*sizeof(int));
    int i,j=0;
    for(i=0;i<n;i++){
        ans[j++]=nums[i];
        ans[j++]=nums[i+n];
    }
    *rs=ns;
    return ans;
}