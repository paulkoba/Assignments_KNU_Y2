// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int out = 0;
        while(n) {
            n /= 5;
            out += n;
        }
        return out;
    }
};