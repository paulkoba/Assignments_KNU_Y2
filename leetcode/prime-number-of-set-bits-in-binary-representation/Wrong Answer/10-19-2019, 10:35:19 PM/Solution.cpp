// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation

static const int isPrime[33] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int output = 0;
        while(L < R) {
            int t = L;
            int count = 0;
            while(t) {
                t &= (t - 1);
                count++;
            }
            ++L;
            output += isPrime[count];
        }
        return output;
    }
};