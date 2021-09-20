// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> output;
        auto l = inorderTraversal(root->left);
        auto r = inorderTraversal(root->right);
        output.insert(output.end(), l.begin(), l.end());
        output.push_back(root->val);
        output.insert(output.end(), r.begin(), r.end());
        return output;
    }
};