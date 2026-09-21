long long* resultArray(int* n, int ns, int k, int* rs) {

    long long *ans = calloc(k, sizeof(long long));
    long long *dp = calloc(k, sizeof(long long));

    int i, r, nr;

    *rs = k;

    for(i = 0; i < ns; i++) {

        long long *next = calloc(k, sizeof(long long));

        nr = n[i] % k;

        next[nr]++;

        for(r = 0; r < k; r++) {
            if(dp[r] > 0) {
                int x = (r * nr) % k;
                next[x] += dp[r];
            }
        }

        for(r = 0; r < k; r++) {
            ans[r] += next[r];
        }

        free(dp);
        dp = next;
    }

    free(dp);

    return ans;
}