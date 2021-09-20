// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
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