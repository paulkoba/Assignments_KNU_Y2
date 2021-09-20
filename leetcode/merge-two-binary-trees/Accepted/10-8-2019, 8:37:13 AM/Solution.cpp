// https://leetcode.com/problems/merge-two-binary-trees

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        
        TreeNode* output = new TreeNode(t1->val + t2->val);
        output->left = mergeTrees(t1->left, t2->left);
        output->right = mergeTrees(t2->right, t1->right);
        
        return output;
    }
};