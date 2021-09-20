// https://leetcode.com/problems/path-sum-ii

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
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& output, vector<int>& currentPath) {
        if(!root) return;

        currentPath.push_back(root->val);
        
        if(!root->left && !root->right) {
            if(targetSum == root->val) output.push_back(currentPath);
        } else if(!root->left) {
            dfs(root->right, targetSum - root->val, output, currentPath);
        } else if(!root->right) {
            dfs(root->left, targetSum - root->val, output, currentPath);
        } else {
            dfs(root->right, targetSum - root->val, output, currentPath);
            dfs(root->left, targetSum - root->val, output, currentPath);
        }
        
        currentPath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> output;
        vector<int> currentPath;
        
        dfs(root, targetSum, output, currentPath);
        
        return output;
    }
};