// https://leetcode.com/problems/xor-operation-in-an-array

class Solution {
public:
    int xorOperation(int n, int start) {
        int output = 0;
        for(int i = 0; i < n; ++i) {
            output ^= start + 2 * i;
        }
        return output;
    }
};