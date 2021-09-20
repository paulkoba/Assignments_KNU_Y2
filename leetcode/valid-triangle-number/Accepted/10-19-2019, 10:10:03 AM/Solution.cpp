// https://leetcode.com/problems/valid-triangle-number

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int output = 0;
        for(int i = 0; i < (sz - 2); ++i) {
            int right = i + 2;
            if(nums[i] == 0) continue;
            for(int j = i + 1; j < (sz - 1); ++j) {
                while(right < sz && (nums[i] + nums[j]) > nums[right]) right++;
                output += right - j - 1;
            }
        }
        
        return output;
    }
};