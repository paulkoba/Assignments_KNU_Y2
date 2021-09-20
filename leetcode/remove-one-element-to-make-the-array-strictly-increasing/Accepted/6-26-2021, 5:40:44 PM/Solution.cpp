// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        if(nums.size() < 3) return true;
        
        bool removed = false;
        auto v1 = nums;
        auto v2 = nums;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] <= nums[i - 1]) {
                v1.erase(v1.begin() + i - 1);
                v2.erase(v2.begin() + i);
                break;
            }
        }
        bool flag = true;
        for(int i = 1; i < v1.size(); ++i) {
            if(v1[i] <= v1[i - 1]) {
                flag = false;
            }
        }
        if(flag) return true;
        flag = true;
        for(int i = 1; i < v2.size(); ++i) {
            if(v2[i] <= v2[i - 1]) {
                flag = false;
            }
        }
        if(flag) return true;

        return false;
    }
};