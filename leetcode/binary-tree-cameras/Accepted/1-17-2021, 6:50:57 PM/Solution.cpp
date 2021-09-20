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
    int count = 0;
    
    int minCameraRecursive(TreeNode* root) {
        if(!root) return 1;
        
        int l = minCameraRecursive(root->left);
        int r = minCameraRecursive(root->right);
        
        if(!root->left || !root-> right) {
            if(!root->left && !root->right) {
                return 0;    
            }
            
            if(root->left) {
                if(l == 0) {
                    ++count;
                    return 2;
                }

                if(l == 2) {
                    return 1;
                }
            } else {
                if(r == 0) {
                    ++count;
                    return 2;
                }
                
                if(r == 2) {
                    return 1;
                }
            }
            
            return 0;
        }
        
        if(l == 0 || r == 0) {
            ++count;
            return 2;
        }
        
        if(l == 2 || r == 2) {
            return 1;
        }
        
        return 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        count = 0;
        
        if(!root) return 0;
                        
        int res = minCameraRecursive(root);
        
        return count + (res == 0);
    }
};