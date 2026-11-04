/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* create(int* nums, int l, int r)
{
    if(l > r)
        return NULL;
    int mid = (l + r) / 2;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = create(nums, l, mid - 1);
    root->right = create(nums, mid + 1, r);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return create(nums, 0, numsSize - 1);
}