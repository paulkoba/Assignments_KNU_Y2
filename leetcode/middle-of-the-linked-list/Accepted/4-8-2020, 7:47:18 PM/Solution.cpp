// https://leetcode.com/problems/middle-of-the-linked-list

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