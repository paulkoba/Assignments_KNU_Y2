// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
        int out = 0;
        for(int i = left; i <= right; ++i) {
            out += binary_search(primes.begin(), primes.end(), __builtin_popcount(i));
        }
        
        return out;
    }
};