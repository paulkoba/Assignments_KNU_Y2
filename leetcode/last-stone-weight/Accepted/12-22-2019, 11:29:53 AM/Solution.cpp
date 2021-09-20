// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        size_t sz = stones.size();
        if(sz == 0) return 0;
        make_heap(stones.begin(), stones.end());
        while(sz >= 2) {
            pop_heap(stones.begin(), stones.begin() + sz);
            --sz;
            pop_heap(stones.begin(), stones.begin() + sz);
            stones[sz - 1] = stones[sz] - stones[sz - 1];
            push_heap(stones.begin(), stones.begin() + sz);
        }
        
        return stones[0];
    }
};