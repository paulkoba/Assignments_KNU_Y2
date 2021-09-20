// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
private:
    int removeNthFromEndHelper(ListNode* head, int n) {
        if(!head) return 0;
        
        int position = removeNthFromEndHelper(head->next, n);
        
        if(n == position) {
            ListNode* headTemp = head->next;
            head->next = head->next->next;
            delete headTemp;
        }
        
        return position + 1;
    }
    
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = new ListNode(0, head);
        
        removeNthFromEndHelper(head, n);
        
        ListNode* tempHead = head;
        head = head->next;
        delete tempHead;
        
        return head;
    }
};