// https://leetcode.com/problems/path-sum-iii

int pathSumInner(TreeNode* root, int sum) {
    if(!root) return 0;
    return pathSumInner(root->left, sum - root->val) + pathSumInner(root->right, sum - root->val) + (sum == root->val);
}

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root) return pathSumInner(root, sum + root->val);
        return 0;
    }
};