// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void flatten(TreeNode* root, vector<TreeNode*>& ll) {
        if(!root) return;
        
        ll.push_back(root);
        flatten(root->left, ll);
        flatten(root->right, ll);
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        
        vector<TreeNode*> ll;
        flatten(root, ll);
        
        int sz = ll.size();
        
        for(int i = 0; i < sz - 2; ++i) {
            ll[i]->left = nullptr;
            ll[i]->right = ll[i + 1];
        }
        ll[sz - 1]->left = nullptr;
        ll[sz - 1]->right = nullptr;
    }
};