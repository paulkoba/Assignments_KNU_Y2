// https://leetcode.com/problems/kth-smallest-element-in-a-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int numElements(TreeNode* root) {
    if(!root) return 0;
    return numElements(root->left) + numElements(root->right) + 1;
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int t = numElements(root->left) + 1;
        if(t == k) return root->val;
        if(t < k) return kthSmallest(root->right, k - t);
        return kthSmallest(root->left, k);
    }
};