// https://leetcode.com/problems/binary-tree-postorder-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> right = postorderTraversal(root->right);
        vector<int> left = postorderTraversal(root->left);
        left.insert(left.end(), right.begin(), right.end());
        left.push_back(root->val);
        return left;
    }
};