// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i : nums) ++count[i];
        for(const auto& p : count) if(p.second == 1) return p.first;
        return -1;
    }
};