// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copied;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(copied.find(node) != copied.end()) return copied[node];
        
        Node* output = new Node(node->val);
        copied[node] = output;
        
        for(Node* ptr : node->neighbors) {
            output->neighbors.push_back(cloneGraph(ptr));
        }
        
        return output;
    }
};