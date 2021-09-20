// https://leetcode.com/problems/binary-tree-cameras

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
private:
    void findParents(TreeNode* root,  unordered_map<TreeNode*, TreeNode*>& parents) {
        if(!root) return;
        parents[root->left] = root;
        parents[root->right] = root;
        
        findParents(root->left, parents);
        findParents(root->right, parents);
    }
        
    int minCameraRecursive(TreeNode* root, unordered_map<TreeNode*, int>& status, unordered_map<TreeNode*, TreeNode*>& parents) {
        if(!root) return 1;
        
        if(status.find(root) != status.end()) return status[root];
        
        int l = minCameraRecursive(root->left, status, parents);
        int r = minCameraRecursive(root->right, status, parents);
        
        if(status.find(root) != status.end()) return status[root];
        
        if(!root->left || !root-> right) {
            if(!root->left && !root->right) {
                return status[root] = 0;    
            }
            
            if(root->left) {
                if(l == 0) {
                    status[parents[root]] = 1;
                    status[root->left] = 1;
                    status[root->right] = 1;
                    
                    return status[root] = 2;
                }

                if(l == 2) {
                    return status[root] = 1;
                }
            } else {
                if(r == 0) {
                    status[parents[root]] = 1;
                    status[root->left] = 1;
                    status[root->right] = 1;
                    
                    return status[root] = 2;
                }

                if(r == 2) {
                    return status[root] = 1;
                }
            }
            
            return status[root] = 0;
        }
        
        if(l == 0 || r == 0) {
            status[parents[root]] = 1;
            status[root->left] = 1;
            status[root->right] = 1;
            
            return status[root] = 2;
        }
        
        if(l == 2 || r == 2) {
            return status[root] = 1;
        }
        
        return status[root] = 0;
        
    }
public:
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        
        unordered_map<TreeNode*, int> status; //0 - not lit, 1 - lit, 2 - camera
        unordered_map<TreeNode*, TreeNode*> parents;

        findParents(root, parents);
        
        parents[nullptr] = nullptr;
        
        minCameraRecursive(root, status, parents);
        int count = 0;
        
        status[nullptr] = 1;
        
        for(auto& a : status) {
            count += (a.second == 2);
        }
        
        return count + (status[root] == 0 || status[root->left] == 0 || status[root->right] == 0);
    }
};