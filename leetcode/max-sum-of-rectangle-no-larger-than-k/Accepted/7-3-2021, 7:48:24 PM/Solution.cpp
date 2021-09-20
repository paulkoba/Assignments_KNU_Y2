// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int ceiling) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = numeric_limits<int>::min();
        
        for(int i = 0; i < m; ++i) {
            vector<int> c(n);
            
            for(int j = i; j < m; ++j) {
                for(int k = 0; k < n; ++k) {
                    c[k] += matrix[j][k];
                }
                
                set<int> s;
                s.insert(0);
                int pref = 0;
                for(int u = 0; u < n; ++u) {
                    pref += c[u];
                    auto res = s.lower_bound(pref - ceiling);
                    if(res != s.end()) result = max(pref - *res, result);
                    s.insert(pref);
                }
            }
        }
        
        return result;
    }
};