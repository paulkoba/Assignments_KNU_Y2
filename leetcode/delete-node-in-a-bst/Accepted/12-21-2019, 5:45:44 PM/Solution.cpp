// https://leetcode.com/problems/delete-node-in-a-bst

TreeNode* insertRight(TreeNode* left, TreeNode* right) {
    if(!left) return right;
    left->right = insertRight(left->right, right);
    return left;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            return insertRight(root->left, root->right);
        }
    }
};