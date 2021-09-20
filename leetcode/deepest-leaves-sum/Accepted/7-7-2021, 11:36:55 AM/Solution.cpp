// https://leetcode.com/problems/deepest-leaves-sum

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
    int depth(TreeNode* root) {
        if(!root) return 0;
        
        return max(1 + depth(root->left), 1 + depth(root->right)); 
    }
    
    int sumAtDepth(TreeNode* root, int d) {
        if(!root) return 0;
        if(d == 1) return root->val;
        
        return sumAtDepth(root->left, d - 1) + 
            sumAtDepth(root->right, d - 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        return sumAtDepth(root, depth(root));
    }
};