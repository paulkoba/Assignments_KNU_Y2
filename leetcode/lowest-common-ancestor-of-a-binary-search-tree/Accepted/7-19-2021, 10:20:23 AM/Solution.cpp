// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        if(!root) return;
        dfs(root->left, parents);
        dfs(root->right, parents);
        
        if(root->left) parents[root->left] = root;
        if(root->right) parents[root->right] = root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parents;
        dfs(root, parents);
        
        set<TreeNode*> seen;
        
        while(p) {
            seen.insert(p);
            p = parents[p];
        }
        
        while(q) {
            if(seen.find(q) != seen.end()) return q;
            q = parents[q];
        }
        
        return nullptr;
    }
};