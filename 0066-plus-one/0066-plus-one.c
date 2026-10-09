/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* d, int dS, int* rS) {
        int i;
    for(i = dS - 1; i >= 0; i--) {
        if(d[i] < 9) {
            d[i]++;
            *rS= dS;
            return d;
        }
        d[i]=0;
    }
    int *res = (int*)malloc((dS+ 1) * sizeof(int));
    res[0] = 1;
    for(i = 1; i <= dS; i++)
        res[i] = 0;
    *rS = dS + 1;
    return res;
}