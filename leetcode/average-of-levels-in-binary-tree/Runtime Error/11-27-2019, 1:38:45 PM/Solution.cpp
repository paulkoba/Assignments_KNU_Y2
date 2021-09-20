// https://leetcode.com/problems/average-of-levels-in-binary-tree

void averageOfLevelsInner(TreeNode* root, vector<pair<int, int>>& output, int level) {
    if(!root) return;
    
    if(output.size() <= level) {
        output.push_back(make_pair(1, root->val));
    } else {
        ++output[level].first;
        output[level].second += root->val;
    }
    
    averageOfLevelsInner(root->left, output, level + 1);
    averageOfLevelsInner(root->right, output, level + 1);
}

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<int, int>> output;
        averageOfLevelsInner(root, output, 0);
        vector<double> A(output.size());
        for(int i = 0; i < output.size(); ++i) {
            A[i] = (double)output[i].second / output[i].first;
        }
        return A;
    }
};