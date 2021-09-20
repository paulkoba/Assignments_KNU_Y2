// https://leetcode.com/problems/binary-tree-level-order-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        
        if(root) lvlOrder(&output, root, 0);
        
        return move(output);
    }
    
    void lvlOrder(vector<vector<int>>* result, TreeNode* root, int level) {
        if(result->size() < (level + 1)) {
            result->push_back({root->val});
        } else {
            (*result)[level].push_back(root->val);
        }
        
        if(root->left) lvlOrder(result, root->left, level + 1);
        if(root->right) lvlOrder(result, root->right, level + 1);
    }
};