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
        
        int result = 0;

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                prefixSum[i][j] = prefixSum[i][j - 1] + prefixSum[i - 1][j] - 
                    prefixSum[i - 1][j - 1] + matrix[i][j];
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(prefixSum[i][j] <= k && prefixSum[i][j] > result) result = prefixSum[i][j];
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int u = i; u < m; ++u) {
                    for(int f = j; f < n; ++f) {
                        int temp = prefixSum[u][f] + prefixSum[i][j] - prefixSum[u][j] - prefixSum[i][f];
                        if(temp <= k && temp > result) result = temp;
                    }
                }
            }
        }
        
        return result;
    }
};