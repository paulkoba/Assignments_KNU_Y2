// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrtl(8LL * n + 1) - 1) / 2;
    }
};