// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        int dp[m][n];
        dp[0][0] = 1;
        
        for(int i = 1; i < m; ++i) {
            if(!g[i][0]) {
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = 0;
            }
        }
        
        for(int j = 1; j < n; ++j) {
            if(!g[0][j]) {
                 dp[0][j] = dp[0][j - 1];
            } else {
                dp[0][j] = 0;
            }
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(g[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};