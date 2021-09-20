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
    int sumRootToLeaf1(TreeNode* root, int accum = 0) {
        if(!root) return accum;
        return sumRootToLeaf1(root->left, (accum << 1) + root->val) + sumRootToLeaf1(root->right, (accum << 1) + root->val);
    }
    
    int sumRootToLeaf(TreeNode* root) { return sumRootToLeaf1(root) / 2; }
};