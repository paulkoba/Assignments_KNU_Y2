// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int N) {
        int maxGap = 0;
        int last = 64;
        while(N) {
            int current = __builtin_ctz(N);
            N &= N - 1;
            maxGap = max(maxGap, current - last);
            last = current;
        }
        return maxGap;
    }
};