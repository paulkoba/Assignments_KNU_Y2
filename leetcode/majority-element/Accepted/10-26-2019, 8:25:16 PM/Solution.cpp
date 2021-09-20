// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int, int> count;
        
        for(int i = 0; i < sz; ++i) {
            if(++count[nums[i]] > sz / 2) return nums[i];
        }
        
        return 0;
    }
};