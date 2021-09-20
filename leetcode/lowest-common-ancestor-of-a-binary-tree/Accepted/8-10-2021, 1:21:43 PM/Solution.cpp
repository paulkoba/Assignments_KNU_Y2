// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

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
    unordered_map<TreeNode*, TreeNode*> parent;
    
    void dfs(TreeNode* root) {
        if(!root) return;
        
        parent[root->left] = root;
        parent[root->right] = root;
        
        dfs(root->left);
        dfs(root->right);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        
        set<TreeNode*> parents;
    
        while(p) {
            parents.insert(p);
            p = parent[p];
        }
        
        while(q) {
            if(parents.find(q) != parents.end()) return q;
            q = parent[q];
        }
        
        return root;
    }
};