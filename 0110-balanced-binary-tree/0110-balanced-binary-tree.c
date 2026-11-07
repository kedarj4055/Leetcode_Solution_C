/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    if(l == -1 || r == -1 || abs(l-r) > 1)
        return -1;
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root) 
{
    return height(root) != -1;
}