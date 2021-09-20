// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root, int64_t max, int64_t min) {
        if(!root) return true;
        if(root->val >= max || root->val <= min) return false;
        
        return isValidBST(root->left, root->val, min) && isValidBST(root->right, max, root->val);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return isValidBST(root, std::numeric_limits<int64_t>::max(), std::numeric_limits<int64_t>::min());
    }
};