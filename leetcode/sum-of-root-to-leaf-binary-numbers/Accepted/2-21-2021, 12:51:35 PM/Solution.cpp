// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    int sumRootToLeaf(TreeNode* root, int accum = 0) {
        if(!root) return accum;
        return (root->left ? sumRootToLeaf(root->left, (accum << 1) + root->val) : 0) 
            + (root->right ? sumRootToLeaf(root->right, (accum << 1) + root->val) : 0)
            + (!root->right && !root->left ? (accum << 1) + root->val : 0);
    }
};