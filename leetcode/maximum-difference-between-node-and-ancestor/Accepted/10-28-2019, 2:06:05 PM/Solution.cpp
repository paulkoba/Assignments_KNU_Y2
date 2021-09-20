// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxDiff(const TreeNode* root, const int lBound, const int rBound) {
    if(!root) return 0;
    return max(max(abs(root->val - lBound), abs(root->val - rBound)), 
               max(maxDiff(root->left, min(root->val, lBound), max(root->val, rBound)), 
               maxDiff(root->right, min(root->val, lBound), max(root->val, rBound))));
}

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return max(maxDiff(root->left, root->val, root->val), maxDiff(root->right, root->val, root->val));
    }
};