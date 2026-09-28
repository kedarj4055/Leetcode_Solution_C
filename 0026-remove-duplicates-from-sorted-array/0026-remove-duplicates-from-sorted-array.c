int removeDuplicates(int* nums, int numsSize) {
    int k=1,i;
    for(i=1;i<numsSize;i++) {
        if(nums[i]!=nums[i-1]){
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}//
