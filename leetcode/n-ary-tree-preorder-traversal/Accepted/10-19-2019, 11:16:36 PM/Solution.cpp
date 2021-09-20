// https://leetcode.com/problems/n-ary-tree-preorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> output = {root->val};
        int sz = root->children.size();
        for(int i = 0; i < sz; ++i) {
            auto v = preorder(root->children[i]);
            output.insert(output.end(), v.begin(), v.end());
        }
        return output;
    }
};