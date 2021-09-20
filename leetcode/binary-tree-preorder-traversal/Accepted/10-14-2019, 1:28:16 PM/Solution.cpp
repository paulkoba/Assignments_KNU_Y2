// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> output{root->val};
        auto l = preorderTraversal(root->left);
        auto r = preorderTraversal(root->right);
        output.insert(output.end(), l.begin(), l.end());
        output.insert(output.end(), r.begin(), r.end());
        return output;
    }
};