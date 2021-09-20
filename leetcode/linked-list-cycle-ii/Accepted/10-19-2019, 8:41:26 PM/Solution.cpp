// https://leetcode.com/problems/linked-list-cycle-ii

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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        
        unordered_map<ListNode*, bool> visited;
        visited[head] = 0;
        while(head->next) {
            if(visited.find(head->next) != visited.end()) return head->next;
            visited[head->next] = 0;
            head = head->next;
        }
        return nullptr;
    }
};