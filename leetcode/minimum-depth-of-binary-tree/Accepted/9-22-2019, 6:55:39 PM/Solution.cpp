// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right) + 1;
        if(!root->right) return fastMinDepth(root->left) + 1;
        return min(fastMinDepth(root->left), fastMinDepth(root->right)) + 1;
    }
    
    int fastMinDepth(TreeNode* root) {
        if(!root->left) return minDepth(root->right) + 1;
        if(!root->right) return fastMinDepth(root->left) + 1;
        return min(fastMinDepth(root->left), fastMinDepth(root->right)) + 1;
    }
};