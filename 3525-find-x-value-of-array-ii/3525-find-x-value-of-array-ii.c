int* resultArray(int* nums, int numsSize, int k, int** queries,
                 int queriesSize, int* queriesColSize, int* returnSize)
{
    int size = 4 * numsSize;

    int *prod = malloc(size * sizeof(int));
    int *cnt = calloc(size * k, sizeof(int));

    /* Build Segment Tree */
    void build(int node, int l, int r)
    {
        if (l == r)
        {
            prod[node] = nums[l] % k;
            cnt[node * k + prod[node]] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        int leftProd = prod[node * 2];
        int rightProd = prod[node * 2 + 1];

        prod[node] = (long long)leftProd * rightProd % k;

        /* Left prefixes */
        for (int x = 0; x < k; x++)
        {
            cnt[node * k + x] = cnt[(node * 2) * k + x];
        }
        for (int x = 0; x < k; x++)
        {
            int newRem = (long long)leftProd * x % k;

            cnt[node * k + newRem] +=
                cnt[(node * 2 + 1) * k + x];
        }
    }
    void update(int node, int l, int r, int pos, int value)
    {
        if (l == r)
        {
            for (int x = 0; x < k; x++)
                cnt[node * k + x] = 0;

            prod[node] = value % k;
            cnt[node * k + prod[node]] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, value);
        else
            update(node * 2 + 1, mid + 1, r, pos, value);

        int leftProd = prod[node * 2];
        int rightProd = prod[node * 2 + 1];

        prod[node] = (long long)leftProd * rightProd % k;

        for (int x = 0; x < k; x++)
            cnt[node * k + x] = cnt[(node * 2) * k + x];

        for (int x = 0; x < k; x++)
        {
            int newRem = (long long)leftProd * x % k;

            cnt[node * k + newRem] +=
                cnt[(node * 2 + 1) * k + x];
        }
    }
    void query(int node, int l, int r,
               int ql, int qr,
               int *currentProd, int *resCnt)
    {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr)
        {
            int oldProd = *currentProd;
            int temp[k];
            for (int x = 0; x < k; x++)
                temp[x] = 0;
            for (int x = 0; x < k; x++)
            {
                int newRem = (long long)oldProd * x % k;
                temp[newRem] += cnt[node * k + x];
            }
            for (int x = 0; x < k; x++)
                resCnt[x] += temp[x];
            *currentProd =
                (long long)oldProd * prod[node] % k;
            return;
        }
        int mid = (l + r) / 2;
        query(node * 2, l, mid,
              ql, qr, currentProd, resCnt);
        query(node * 2 + 1, mid + 1, r,
              ql, qr, currentProd, resCnt);
    }
    build(1, 0, numsSize - 1);
    int *ans = malloc(queriesSize * sizeof(int));
    for (int q = 0; q < queriesSize; q++)
    {
        int index = queries[q][0];
        int value = queries[q][1];
        int start = queries[q][2];
        int x = queries[q][3];
        nums[index] = value;
        update(1, 0, numsSize - 1, index, value);
        int resCnt[k];
        for (int i = 0; i < k; i++)
            resCnt[i] = 0;
        int currentProd = 1;
        query(1, 0, numsSize - 1,
              start, numsSize - 1,
              &currentProd, resCnt);
        ans[q] = resCnt[x];
    }
    free(prod);
    free(cnt);
    *returnSize = queriesSize;
    return ans;
}