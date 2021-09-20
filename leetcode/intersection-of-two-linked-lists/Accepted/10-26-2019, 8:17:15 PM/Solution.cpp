// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        set<ListNode*> a;
        
        while(headA) {
            a.insert(headA);
            headA = headA->next;
        }
        
        auto it = a.end();
        
        while(headB) {
            if(a.find(headB) != it) return headB;
            headB = headB->next;
        }
        
        return nullptr;
    }
};