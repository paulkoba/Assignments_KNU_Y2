// https://leetcode.com/problems/range-sum-of-bst

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return 0;
        int output = (L <= root->val && root->val <= R) ? root->val : 0;
        if(L < root->val) output += rangeSumBST(root->left, L, R);
        if(R > root->val) output += rangeSumBST(root->right, L, R);
        return output;
    }
};