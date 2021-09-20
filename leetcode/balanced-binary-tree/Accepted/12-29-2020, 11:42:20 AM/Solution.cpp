// https://leetcode.com/problems/balanced-binary-tree

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
    pair<bool, int> getBalance(TreeNode* root) {
        if(!root) return make_pair(true, 0);
        
        auto l = getBalance(root->left);
        if(!l.first) return {false, 0};
        auto r = getBalance(root->right);
        if(!r.first) return {false, 0};
        if(abs(l.second - r.second) > 1) return {false, 0};
        int height = max(l.second, r.second) + 1;
        return {true, height};
    }
    
    bool isBalanced(TreeNode* root) {
        return getBalance(root).first;
    }
};