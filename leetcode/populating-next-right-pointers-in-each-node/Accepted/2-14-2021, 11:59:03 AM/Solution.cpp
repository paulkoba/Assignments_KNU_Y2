// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return {};
        
        queue<pair<Node*, int>> bfs;
        bfs.push({root, 0});
        vector<Node*> output;
        
        while(!bfs.empty()) {
            auto front = bfs.front();
            bfs.pop();
            
            if(output.size() > front.second) {
                output[front.second]->next = front.first;
                output[front.second] = front.first;
            } else {
                output.push_back(front.first);
                front.first->next = nullptr;
            }
            
            if(front.first->left) bfs.push({front.first->left, front.second + 1});
            if(front.first->right) bfs.push({front.first->right, front.second + 1});
        }
        
        return root;
    }
};