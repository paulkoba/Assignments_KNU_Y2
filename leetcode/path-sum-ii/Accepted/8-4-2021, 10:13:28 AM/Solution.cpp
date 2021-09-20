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
private:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum, vector<int> currentPath) {
        if(!root) return {};
        currentPath.push_back(root->val);
        if(!root->left && !root->right) {
            int result = accumulate(currentPath.begin(), currentPath.end(), 0);
            if(result == targetSum) return {currentPath};
        }
        auto r1 = pathSum(root->left, targetSum, currentPath);
        auto r2 = pathSum(root->right, targetSum, currentPath);
        
        r1.insert(r1.end(), r2.begin(), r2.end());
        
        return r1;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        return pathSum(root, targetSum, {});
    }
};