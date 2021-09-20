// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::remove(nums.begin(), nums.end(), val);
        
        return nums.size();
    }
};