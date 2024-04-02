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
    void inorderTraversal(TreeNode* root, vector<int>& inorderList) {
        if (root) {
            inorderTraversal(root->left, inorderList);
            inorderList.push_back(root->val);
            inorderTraversal(root->right, inorderList);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> inorderList{};

        inorderTraversal(root, inorderList);
        int min_val = INT_MAX;
        int diff = 0;
        for (int i = 0; i < inorderList.size() - 1; i += 1) {
            diff = inorderList[i + 1] - inorderList[i];
            if (diff < min_val) {
                min_val = diff;
            }
        }
        return min_val;
    }
};
