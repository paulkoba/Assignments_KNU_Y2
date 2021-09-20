// https://leetcode.com/problems/n-ary-tree-level-order-traversal

void levelOrderInner(Node* root, vector<vector<int>>& output, int height) {
    if(output.size() > height) {
        (output.begin() + height)->push_back(root->val);
    } else {
        output.push_back( {root->val} );
    }
    for(Node* child : root->children) levelOrderInner(child, output, height + 1);
}

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> output;
        if(!root) return {};
        levelOrderInner(root, output, 0);
        return output;
    }
};