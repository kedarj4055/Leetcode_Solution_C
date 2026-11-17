/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void solve(struct TreeNode* root, int* arr, int* index)
{
    if(root == NULL)
        return;

    solve(root->left, arr, index);
    solve(root->right, arr, index);

    arr[(*index)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* arr = malloc(100 * sizeof(int));
    *returnSize = 0;

    solve(root, arr, returnSize);

    return arr;
}