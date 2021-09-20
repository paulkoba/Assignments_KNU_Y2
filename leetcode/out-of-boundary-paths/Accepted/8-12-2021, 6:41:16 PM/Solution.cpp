// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n));
        vector<vector<int>> dpNext(m, vector<int>(n));
        int output = 0;
        dp[startRow][startColumn] = 1;
        
        for(int ii = 0; ii < maxMove; ++ii) {
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(i) dpNext[i][j] += dp[i - 1][j];
                    dpNext[i][j] %= 1'000'000'007;

                    if(j) dpNext[i][j] += dp[i][j - 1];
                    dpNext[i][j] %= 1'000'000'007;
                    
                    if(i != m - 1) dpNext[i][j] += dp[i + 1][j];
                    dpNext[i][j] %= 1'000'000'007;

                    if(j != n - 1) dpNext[i][j] += dp[i][j + 1];
                    dpNext[i][j] %= 1'000'000'007;
                }
            }

            for(int i = 0; i < m; ++i) {
                output += dp[i][0];
                output %= 1'000'000'007;
                output += dp[i][n - 1];
                output %= 1'000'000'007;
            }
            
            for(int j = 0; j < n; ++j) {
                output += dp[0][j];
                output %= 1'000'000'007;
                output += dp[m - 1][j];
                output %= 1'000'000'007;
            }
            
            dp = dpNext;
            dpNext = vector<vector<int>>(m, vector<int>(n));
        }
        
        return output;
    }
};