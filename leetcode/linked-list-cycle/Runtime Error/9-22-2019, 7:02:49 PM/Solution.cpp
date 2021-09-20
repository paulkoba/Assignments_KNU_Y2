// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, char> visited;
        while(head->next) {
            head = head->next;
            if(visited.find(head) != visited.end()) return true;
            visited[head] =  0;
        }
        
        return false;
    }
};