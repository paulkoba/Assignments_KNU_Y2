// https://leetcode.com/problems/valid-triangle-number

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int sz = nums.size();
        int output = 0;
        for(int i = sz - 1; i >= 2; --i) {
            int left = 0;
            int mid = i - 1;
            
            while(left < mid) {
                if(nums[left] + nums[mid] > nums[i]) {
                    output += mid - left;
                    --mid;
                } else {
                    ++left;
                }
            }
        }
        
        return output;
    }
};