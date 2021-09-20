// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        ListNode* middle = head;
        
        while(true) {
            if(head->next) {
                if(head->next->next) {
                    head = head->next->next;
                    middle = middle->next;
                } else {
                    return middle->next;
                }
            } else {
                return middle;
            }
        }
    }
};