// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    unordered_map<TreeNode*, int> sumsCache;
    
    int maxPathSumHelper(TreeNode* root) {
        if(!root) return 0;
        if(sumsCache.find(root) != sumsCache.end()) return sumsCache[root];
        
        return sumsCache[root] = root->val + max(maxPathSumHelper(root->left), maxPathSumHelper(root->right));
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        
        int a = max(maxPathSumHelper(root->left), 0);
        int b = max(maxPathSumHelper(root->right), 0);
        int c = max(maxPathSum(root->left), maxPathSum(root->right));
        return max(a + b + root->val, c);
    }
};