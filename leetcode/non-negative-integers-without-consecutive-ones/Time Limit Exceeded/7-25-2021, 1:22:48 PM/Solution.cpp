// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones

class Solution {
public:
    int findIntegers(int n) {
        int output = 0;
        for(int i = 0; i <= n; ++i) output += (i & (i << 1)) == 0;
        
        return output;
    }
};