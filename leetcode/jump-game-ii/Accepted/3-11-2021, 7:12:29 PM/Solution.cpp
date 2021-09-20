// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), numeric_limits<int>::max());
        
        dp[0] = 0;
        
        while(dp[nums.size() - 1] == numeric_limits<int>::max()) {
            for(int j = 0; j < nums.size(); ++j) {
                if(dp[j] == numeric_limits<int>::max()) break;
                for(int k = j + 1; k < min(j + nums[j] + 1, (int)dp.size()); ++k) {
                    dp[k] = min(dp[k] - 1, dp[j]) + 1;
                }
            }
        }
        
        return dp[nums.size() - 1];
    }
};