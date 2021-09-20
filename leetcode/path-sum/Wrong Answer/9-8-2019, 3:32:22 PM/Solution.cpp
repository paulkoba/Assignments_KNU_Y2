// https://leetcode.com/problems/path-sum

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return hasPathSum_(root, sum);
    }
    
    bool hasPathSum_(TreeNode* root, int sum) {
        if(!root) return sum == 0;
        
        if(hasPathSum_(root->left, sum - root->val)) return true;
        if(hasPathSum_(root->right, sum - root->val)) return true;
        
        return false;
    }
};