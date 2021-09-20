// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return s <= 0;
        int sum = 0;
        int tail = 0;
        int minSubLen = numeric_limits<int>::max();
        for(int i = 0; i < sz; ++i) {
            sum += nums[i];
            if(sum < s) continue;
            while(tail <= i && sum >= s) {
                sum -= nums[tail++];
            }
            minSubLen = min(minSubLen, i - tail + 2);
        }
        return minSubLen;
    }
};