// https://leetcode.com/problems/maximum-depth-of-n-ary-tree

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int maxD = 1;
        for(Node* child : root->children) maxD = max(maxD, maxDepth(child) + 1);
        return maxD;
    }
};