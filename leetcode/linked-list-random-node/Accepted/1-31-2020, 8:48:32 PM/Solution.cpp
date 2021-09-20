// https://leetcode.com/problems/linked-list-random-node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
uint64_t m_state = 0xF57BA57EABCD193D;

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
        numbers.push_back(head->val);
        ++length;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        m_state ^= m_state << 13;
        m_state ^= m_state >> 17;
        m_state ^= m_state << 5;
        return numbers[m_state % length];
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