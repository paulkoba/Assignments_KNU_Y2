// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        ListNode* last = new ListNode(0);
        ListNode* head = last;
        for(int i = 0; i < size; ++i) {
            if(!lists[i]) {
                lists.erase(lists.begin() + i);
                size--;
            }
        }
        
        while(size != 0) {
            int min = 0;
            for(int i = 0; i < size; ++i) {
                    if(lists[i]->val < lists[min]->val) {
                        min = i;
                    }
            }
            
            ListNode* newLast = new ListNode(lists[min]->val);
            last->next = newLast;
            last = newLast;
            
            lists[min] = lists[min]->next;
            if(!lists[min]) {
                lists.erase(lists.begin() + min);
                --size;
            }
        }
        
        return head->next;
    }
};