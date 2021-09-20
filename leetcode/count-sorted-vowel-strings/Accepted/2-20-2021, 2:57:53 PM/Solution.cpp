// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n, vector(5, 0));
        
        for(int j = 0; j < 5; ++j) 
            dp[0][j] = 1;
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 5; ++j) {
                for(int k = j; k < 5; ++k) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        
        return dp[n - 1][4] + dp[n - 1][3] + dp[n - 1][2] + dp[n - 1][1] + dp[n - 1][0];
    }
};