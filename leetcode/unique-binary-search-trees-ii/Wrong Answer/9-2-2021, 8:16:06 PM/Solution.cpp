// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    void incRecursive(TreeNode* root, int n) {
        if(!root) return;
        root->val += n;
        
        incRecursive(root->left, n);
        incRecursive(root->right, n);
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 1) return { new TreeNode(1) };
        if(n == 0) return { nullptr };
        
        vector<TreeNode*> output;
        
        for(int i = 1; i <= n; ++i) {
            auto r1 = generateTrees(i - 1);
            auto r2 = generateTrees(n - i);
            for(const auto& p : r2) incRecursive(p, i);
            
            for(const auto& el1 : r1) {
                for(const auto& el2 : r2) {
                    output.push_back(new TreeNode(i, el1, el2));
                }
            }
        }
        
        return output;
    }
};