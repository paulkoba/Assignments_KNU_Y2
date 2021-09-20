// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int m = 0;
        int current = 0;
        for(int i = 0; i < nums.size(); ++i) {
            current += nums[i];
            m = min(current, m);
        }
        
        return max(1 - m, 1);
    }
};