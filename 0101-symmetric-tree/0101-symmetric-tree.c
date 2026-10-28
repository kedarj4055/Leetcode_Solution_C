/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) {
        if (root == NULL) return true;
    struct TreeNode *q[2000];
    int front = 0, rear = 0;
    q[rear++] = root->left;
    q[rear++] = root->right;
    while (front < rear) {
        struct TreeNode *a = q[front++];
        struct TreeNode *b = q[front++];
        if (a == NULL && b == NULL) continue;
        if (a == NULL || b == NULL) return false;
        if (a->val != b->val) return false;
        q[rear++] = a->left;
        q[rear++] = b->right;
        q[rear++] = a->right;
        q[rear++] = b->left;
    }
    return true;
}