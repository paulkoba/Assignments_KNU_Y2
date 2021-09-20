// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int numTilings(int N) {
        const int modulo = (int)1e9 + 7;
        vector<int> dp(1024);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        if(N )
        for(int i = 4; i <= N; ++i) {
            dp[i] = 2 * dp[i - 1] % modulo + dp[i - 3];
            dp[i] %= modulo;
        }
        return dp[N];
    }
};