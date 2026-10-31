void pre(struct TreeNode* root, int *a, int *i) {
    if (root == NULL)
        return;
    a[(*i)++] = root->val;
    pre(root->left, a, i);
    pre(root->right, a, i);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *a = malloc(100 * sizeof(int));
    *returnSize = 0;
    pre(root, a, returnSize);
    return a;
}