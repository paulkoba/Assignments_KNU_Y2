// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    int64_t findSum(TreeNode* root, vector<int64_t>& sum) {
        if(!root) return 0;
        
        int64_t a = findSum(root->left, sum);
        int64_t b = findSum(root->right, sum);
        int64_t c = a + b + root->val;
        sum.push_back(c);
        
        return c;
    }
    
    
    
    int64_t maxProduct(TreeNode* root) {
        vector<int64_t> rr;
        int64_t r1 = findSum(root, rr);
        int64_t result = 0;
        
        for(int i = 0; i < rr.size(); ++i) {
            result = max(result, (r1 - rr[i]) * rr[i]);
        }
        
        return (result % 1'000'000'007);
    }
};