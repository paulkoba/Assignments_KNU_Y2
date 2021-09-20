// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return nullptr;
        if(target == original) return cloned;
        
        auto ptr = getTargetCopy(original->left, cloned->left, target);
        if(ptr) return ptr;
        
        return getTargetCopy(original->right, cloned->right, target);
    }
};