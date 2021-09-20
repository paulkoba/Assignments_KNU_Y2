// https://leetcode.com/problems/n-ary-tree-postorder-traversal

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

void postorder_inner(Node* root, vector<int>& output) {
    for(Node* child : root->children) postorder_inner(child, output);
    output.push_back(root->val);
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> output;
        postorder_inner(root, output);
        return output;
    }
};