// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(8 * n + 1) - 1) / 2;
    }
};