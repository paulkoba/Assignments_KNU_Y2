// https://leetcode.com/problems/count-vowels-permutation

class Solution {
public:    
    int countVowelPermutation(int n) {
        vector<int64_t> dp = {1, 1, 1, 1, 1};
        vector<int64_t> cpdp = {1, 1, 1, 1, 1};

        for(int i = 1; i < n; ++i) {
            cpdp[0] = dp[1] + dp[2] + dp[4];
            cpdp[1] = dp[0] + dp[2];
            cpdp[2] = dp[1] + dp[3];
            cpdp[3] = dp[2];
            cpdp[4] = dp[2] + dp[3];
            
            dp = cpdp;
            
            for(int i = 0; i < 5; ++i) dp[i] %= 1000000007;
        }
        
        return (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % 1000000007;
    }
};