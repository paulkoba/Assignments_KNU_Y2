// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

#pragma GCC optimize ("-Ofast,-ffast-math")

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = numeric_limits<int>::min();

        vector<vector<int>> prefixSum(m, vector<int>(n));
        
        for(int j = 0; j < n; ++j) {
            prefixSum[0][j] = matrix[0][j];
            for(int i = 1; i < m; ++i) {
                prefixSum[i][j] = matrix[i][j] + prefixSum[i][j];
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int li = i; li < m; ++li) {
                for(int j = 0; j < n; ++j) {
                    int sum = 0;
                    for(int lj = j; lj < n; ++lj) {
                        sum += prefixSum[li][lj] + matrix[i][lj] - prefixSum[i][lj];
                        
                        if(sum > result && sum <= k) result = sum;
                    }
                }
            }
        }
        
        return result;
    }
};