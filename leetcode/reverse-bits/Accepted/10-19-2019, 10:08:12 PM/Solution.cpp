// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int output = 0;
        for(int i = 0; i < 32; ++i) {
            if((n - 1) == (n & (n - 1))) {
                output = (output << 1) + 1;
            } else {
                output = output << 1;
            }
            n = n >> 1;
        }
        return output;
    }
};