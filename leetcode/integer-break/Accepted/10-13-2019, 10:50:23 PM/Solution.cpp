// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2 || n == 3) return n - 1;
        
        vector<int> maxProd(++n);
        maxProd[0] = 1;
        for(int i = 1; i < n; ++i) {
            int current = 0;
            for(int j = 0; j <= i; ++j) {
                current = max(current, maxProd[i - j] * j);
            }
            maxProd[i] = current;
        }
        
        return maxProd[n - 1];
    }
};