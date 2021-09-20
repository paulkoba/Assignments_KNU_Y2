// https://leetcode.com/problems/symmetric-tree

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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
    bool isMirror(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        if(!a || !b) return false;
        return a->val == b->val &&
            isMirror(a->left, b->right) &&
            isMirror(b->left, a->right);
    }
};