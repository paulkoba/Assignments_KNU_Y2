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
    TreeNode* balanceBST(vector<TreeNode*>& v, int i, int j) {
        if(j < i) return nullptr;
        
        v[(i + j) / 2]->left = balanceBST(v, i, (i + j) / 2 - 1);
        v[(i + j) / 2]->right = balanceBST(v, (i + j) / 2 + 1, j);
        
        return v[(i + j) / 2];
    }
    
    void toVec(vector<TreeNode*>& v, TreeNode* root) {
        if(!root) return;
        
        toVec(v, root->left);
        v.push_back(root);
        toVec(v, root->right);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        
        toVec(arr, root);
        
        return balanceBST(arr, 0, arr.size() - 1);
    }
};