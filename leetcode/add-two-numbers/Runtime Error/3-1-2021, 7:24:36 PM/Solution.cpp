// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = nullptr;
        ListNode* output = new ListNode(0, nullptr);
        ListNode* current = output;
        while(l1 && l2) {
            prev = current;
            current->val += l1->val + l2->val;
            
            if(current->val >= 10) {
                current->next = new ListNode(1);
                current->val = current->val - 10;
            }
            
            l1 = l1->next;
            l2 = l2->next;
            
            if(!current->next) {
                current->next = new ListNode(0);
            }
            
            current = current->next;
        }
        
        while(l1) {
            prev = current;
            current->val += l1->val;
            
            if(current->val >= 10) {
                current->next = new ListNode(1);
                current->val = current->val - 10;
            }
            
            l1 = l1->next;
            
            if(!current->next) {
                current->next = new ListNode(0);
            }
            
            current = current->next;
        }
           
        while(l2) {
            prev = current;
            current->val += l2->val;
            
            if(current->val >= 10) {
                current->next = new ListNode(1, nullptr);
                current->val = current->val - 10;
            }
            
            l1 = l1->next;
            
            if(!current->next) {
                current->next = new ListNode(0);
            }
            
            current = current->next;
        }
        
        if(current->val == 0) {
            prev->next = 0;
            delete current;
        }
        
        return output;
    }
};