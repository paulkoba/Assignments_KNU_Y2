// https://leetcode.com/problems/maximum-binary-tree

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
private:
    TreeNode* constructMBT(const vector<int>& nums, int first, int last) {
        if(first == last) return nullptr;
        int maxIndex = first;
        for(int i = first; i < last; ++i) {
            if(nums[maxIndex] < nums[i]) maxIndex = i;    
        }
        TreeNode* output = new TreeNode(nums[maxIndex]);
        output->left = constructMBT(nums, first, maxIndex);
        output->right = constructMBT(nums, maxIndex + 1, last);
        return output;
    }
public:
    TreeNode* constructMaximumBinaryTree(const vector<int>& nums) {
        return constructMBT(nums, 0, nums.size());
    }
};