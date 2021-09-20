// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int dst = 0;
        while(x) {
            x = x & (x - 1);
            ++dst;
        }
        return dst;
    }
};