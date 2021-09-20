// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && t % n == 0;
    }
    const static int t = pow(3, int(log((double)numeric_limits<int>::max()) / log(3.0)));
};