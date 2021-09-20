// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> rf;
        Node* head_ = head;
        
        while(head) {
            rf[head] = new Node();
            rf[head]->val = head->val;
            head = head->next;
        }
        
        Node* head_final = rf[head_];
        
        while(head_) {
            rf[head_]->next = rf[head_->next];
            rf[head_]->random = rf[head_->random];
            head_ = head_->next;
        }
        
        return head_final;
    }
};