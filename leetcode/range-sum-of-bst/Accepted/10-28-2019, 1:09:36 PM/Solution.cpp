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
        if(L <= root->val && root->val <= R) 
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        int output = 0;
        if(L < root->val) {
            output += rangeSumBST(root->left, L, R);
        } else {
            output += rangeSumBST(root->right, L, R);
        }
        return output;
    }
};