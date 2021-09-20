// https://leetcode.com/problems/reverse-linked-list-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {        
        if(left == right) return head;
        if(!head || !head->next) return head;
        
        head = new ListNode(0, head);
        ++left;
        ++right;
        
        ListNode* output = head;
        
        while(left > 2) {
            head = head->next;
            --left;
            --right;
        }
        
        ListNode* lReverse = head;
        ListNode* lRevNext = head->next;
        ListNode* next = nullptr, *prev = nullptr, *curr = head->next;
        while(--right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        lRevNext->next = next;
        
        lReverse->next = prev;
        
        ListNode* res = output->next;
        delete output;
        return res;
    }
};