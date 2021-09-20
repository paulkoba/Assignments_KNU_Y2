// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    void inorder(TreeNode* root, vector<int>& a) {
        if(!root) return;
        
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        inorder(root, a);
        
        int last = a.size() - 1;
        int first = 0;
        while(true) {
            while(last >= first && a[first] + a[last] > k) --last;
            while(last >= first && a[first] + a[last] < k) ++first;
            if(last >= first && a[first] + a[last] == k) return true;
            
            if(last < first) return false;
        }
    }
};