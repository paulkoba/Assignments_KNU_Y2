// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int sz = nums.size();
        int count = accumulate(nums.begin(), nums.end(), 0);
        int currentSum = 0;
        int maxSum = 0;
        int currentZeroBalance = 0;
        int iter = 0;
        if(count + k > sz) return sz;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                if(currentZeroBalance == k) {
                    while(currentZeroBalance == k) {
                        currentZeroBalance -= nums[iter] == 0;
                        currentSum -= nums[iter] == 1;
                        ++iter;
                    }
                }
                ++currentZeroBalance;
            } else {
                ++currentSum;
                maxSum = max(currentSum, maxSum);
            }
        }
        
        return maxSum + k;
    }
};