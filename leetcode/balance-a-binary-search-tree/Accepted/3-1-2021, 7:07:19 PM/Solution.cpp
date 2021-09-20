// https://leetcode.com/problems/balance-a-binary-search-tree

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
    TreeNode* balanceBST(vector<int>& v, int i, int j) {
        if(j < i) return nullptr;
        if(j == i) return new TreeNode(v[i], nullptr, nullptr);
        
        TreeNode* left = balanceBST(v, i, (i + j) / 2 - 1);
        TreeNode* right = balanceBST(v, (i + j) / 2 + 1, j);
        
        return new TreeNode(v[(i + j) / 2], left, right);
    }
    
    void toVec(vector<int>& v, TreeNode* root) {
        if(!root) return;
        
        toVec(v, root->left);
        v.push_back(root->val);
        toVec(v, root->right);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        
        toVec(arr, root);
        
        return balanceBST(arr, 0, arr.size() - 1);
    }
};