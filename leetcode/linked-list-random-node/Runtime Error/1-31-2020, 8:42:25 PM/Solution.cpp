// https://leetcode.com/problems/linked-list-random-node

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        while(head->next) {
            numbers.push_back(head->val);
            head = head->next;
            ++length;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return numbers[rand() % length];
    }
    
private:
    size_t length = 0;
    vector<int> numbers;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */