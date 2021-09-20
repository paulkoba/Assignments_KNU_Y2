// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        size_t first = 0, sz = nums.size();
        size_t pos = 0, last = sz - 1;
        while(pos <= last) {
            if(nums[pos] == 2) {
                swap(nums[pos], nums[last--]);
                continue;
            }
            if(nums[pos] == 0) {
                swap(nums[pos], nums[first++]);
            }
            ++pos;
        }
    }
};