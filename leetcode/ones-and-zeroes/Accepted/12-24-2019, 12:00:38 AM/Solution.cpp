// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        size_t sz = strs.size();
        vector<pair<int, int>> data(sz);
        for(size_t i = 0; i < sz; ++i)
            for(char ch : strs[i])
                ch == '0' ? ++data[i].second : ++data[i].first;
        
        sort(data.begin(), data.end());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        for(int i = 0; i < sz; ++i) {
            for(int j = n; j >= 0; --j) {
                if(data[i].first > j) continue;
                for(int k = m; k >= 0; --k) {
                    if(data[i].second > k) continue;
                    dp[j][k] = max(dp[j][k], dp[j - data[i].first][k - data[i].second] + 1);
                }
            }
        }
        
        return dp[n][m];
    }
};