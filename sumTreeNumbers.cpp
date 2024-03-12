/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return postOrderTraversal(root, sum);
    }

    int postOrderTraversal(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        sum = sum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        }
        int leftSum = postOrderTraversal(root->left, sum);
        int rightSum = postOrderTraversal(root->right, sum);
        return leftSum + rightSum;
    }
};
