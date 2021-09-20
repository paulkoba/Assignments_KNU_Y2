// https://leetcode.com/problems/recover-binary-search-tree

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
    void inorderTraversal(vector<TreeNode*>& data, TreeNode* root) {
        if(!root) return;
        inorderTraversal(data, root->left);
        data.push_back(root);
        inorderTraversal(data, root->right);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        inorderTraversal(inorder, root);
        int n = inorder.size();
        for(int i = n - 1; i > 0; --i) {
            if(inorder[i]->val < inorder[i - 1]->val) {
                int j = i - 1;
                while(j >= 0 && inorder[i]->val < inorder[j]->val) --j;
                
                swap(inorder[i]->val, inorder[j + 1]->val);
                break;
            }
        }
    }
};