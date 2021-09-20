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
    int findSum(TreeNode* root, vector<int>& sum) {
        if(!root) return 0;
        
        int a = findSum(root->left, sum);
        int b = findSum(root->right, sum);
        int c = a + b + root->val;
        sum.push_back(c);
        
        return c;
    }
    
    
    
    int maxProduct(TreeNode* root) {
        vector<int> rr;
        int r1 = findSum(root, rr);
        int result = 0;
        
        for(int i = 0; i < rr.size(); ++i) {
            result = max(result, (r1 - rr[i]) * rr[i]);
        }
        
        return result;
    }
};