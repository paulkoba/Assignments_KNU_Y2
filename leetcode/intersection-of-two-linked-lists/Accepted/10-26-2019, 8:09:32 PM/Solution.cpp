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
        unordered_map<ListNode*, int> a;
        
        while(headA) {
            a[headA]++;
            headA = headA->next;
        }
        while(headB) {
            if(a.find(headB) != a.end()) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};