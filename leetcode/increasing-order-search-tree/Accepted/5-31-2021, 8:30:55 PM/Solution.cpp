// https://leetcode.com/problems/increasing-order-search-tree

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
    void inorder(TreeNode* root, vector<int>& sol) {
        if(!root) return;
        inorder(root->left, sol);
        sol.push_back(root->val);
        inorder(root->right, sol);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> solution;
        inorder(root, solution);
        
        TreeNode* output = new TreeNode(solution[0]);
        TreeNode* memo = output;
        for(int i = 1; i < solution.size(); ++i) {
            output->right = new TreeNode(solution[i]);
            output = output->right;
        }
        
        return memo;
    }
};