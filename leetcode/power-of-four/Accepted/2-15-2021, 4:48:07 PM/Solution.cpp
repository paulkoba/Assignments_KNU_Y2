// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        return __builtin_popcount(n) == 1 && __builtin_ctz(n) % 2 == 0;
    }
};