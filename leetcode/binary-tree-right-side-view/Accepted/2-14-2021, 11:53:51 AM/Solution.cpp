// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        vector<int> output;
        
        while(!bfs.empty()) {
            auto front = bfs.front();
            bfs.pop();
            
            if(output.size() > front.second) {
                output[front.second] = front.first->val;
            } else {
                output.push_back(front.first->val);
            }
            
            if(front.first->left) bfs.push({front.first->left, front.second + 1});
            if(front.first->right) bfs.push({front.first->right, front.second + 1});
        }
        
        return output;
    }
};