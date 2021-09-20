// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

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
    int longestZigZag(TreeNode* root, bool isLeft) {
        if(!root) return 0;
        
        if(isLeft) {
            return max(longestZigZag(root->right) + 1, longestZigZag(root->left));
        } else {
            return max(longestZigZag(root->right), longestZigZag(root->left) + 1);
        }
    }
    
public:
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        return max(longestZigZag(root->left, true), longestZigZag(root->right, true));
    }
};