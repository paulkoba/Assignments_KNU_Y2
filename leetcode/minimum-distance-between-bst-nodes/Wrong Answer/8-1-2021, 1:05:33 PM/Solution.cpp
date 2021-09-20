// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    int minDiffInBST(TreeNode* root) {
        if(!root) return numeric_limits<int>::max();
        int output = numeric_limits<int>::max();
        
        if(root->left) {
            output = root->val - root->left->val;
            output = min(output, minDiffInBST(root->left));
        }
        
        if(root->right) {
            output = min(output, root->right->val - root->val);
            output = min(output, minDiffInBST(root->right));
        }
        
        return output;
    }
};