// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> prefixSum(m, vector<int>(n));
        
        prefixSum[0][0] = matrix[0][0];
        
        for(int i = 1; i < m; ++i) {
            prefixSum[i][0] = matrix[i][0] + prefixSum[i - 1][0];
        }
        
        for(int i = 1; i < n; ++i) {
            prefixSum[0][i] = matrix[0][i] + prefixSum[0][i - 1];
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                prefixSum[i][j] = prefixSum[i][j - 1] + prefixSum[i - 1][j] - 
                    prefixSum[i - 1][j - 1] + matrix[i][j];
            }
        }
        
        int result = numeric_limits<int>::min();
        
        for(int p = 1; p <= m; ++p) {
            for(int o = 1; o <= n; ++o) {
                for(int i = 0; i <= m - p; ++i) {
                    for(int j = 0; j <= n - o; ++j) {
                        int temp = prefixSum[i + p - 1][j + o - 1];
                        
                        if(i > 0 && j > 0) {
                            temp -= prefixSum[i - 1][j + o - 1] + prefixSum[i + p - 1][j - 1] - 
                                prefixSum[i - 1][j - 1];
                        } else if(i > 0) {
                            temp -= prefixSum[i - 1][j + o - 1];
                        } else if(j > 0) {
                            temp -= prefixSum[i + p - 1][j - 1];
                        }
                        if(temp > result && temp <= k) result = temp;
                    }
                }
            }
        }
        
        return result;
    }
};