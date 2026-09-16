/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* arr, int n, int* returnS) {
    *returnS=n;
    int i;
    for(i=1;i<n;i++){
        arr[i]=arr[i]+arr[i-1];
    }
    return arr;
}