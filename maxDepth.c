// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(struct TreeNode* root) {
    if (root) {
        int depth = 1;
        int l = depth + maxDepth(root->left);
        int r = depth + maxDepth(root->right);
        return l > r ? l : r;
    }
    return 0;
}