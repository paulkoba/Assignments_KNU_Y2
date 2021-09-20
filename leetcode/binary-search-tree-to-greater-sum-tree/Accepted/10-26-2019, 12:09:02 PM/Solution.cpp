// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    TreeNode* bstToGst(TreeNode* root) {
        bstToGstVal(root, 0);
        return root;
    }
private:
    int bstToGstVal(TreeNode* root, int rValue)
    {
        if(!root) return 0;
        int a = bstToGstVal(root->right, rValue);
        int b = bstToGstVal(root->left, rValue + root->val + a);
        root->val += a + rValue;
        return b + root->val - rValue;
    }
};