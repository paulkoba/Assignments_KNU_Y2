// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

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
    void dfs(set<int>& a, TreeNode* root) {
        if(!root) return;
        a.insert(root->val);
        dfs(a, root->left);
        dfs(a, root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> a;
        dfs(a, root);
        if(a.size() < 2) return -1;
        return *(++a.begin());
    }
};