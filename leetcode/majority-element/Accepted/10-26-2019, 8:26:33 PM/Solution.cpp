// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int, int> count;
        
        for(int i = 0; i < sz; ++i) ++count[nums[i]];
        for(const auto& p : count) if(p.second > sz / 2) return p.first;
        
        return 0;
    }
};