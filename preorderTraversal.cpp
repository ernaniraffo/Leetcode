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
private:
    void preorderTraversal(vector<int>& res, TreeNode* root) {
        if (root) {
            res.push_back(root->val);
            preorderTraversal(res, root->left);
            preorderTraversal(res, root->right);
        }
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal(res, root);
        return res;
    }
};
