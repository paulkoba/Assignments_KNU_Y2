// https://leetcode.com/problems/count-primes


class Solution {
public:
    int countPrimes(int n) {
        vector<char> sieve(n);
        int count = 0;
        
        for(int i = 2; i < n; ++i) {
            if(sieve[i] == 0) {
                ++count;
                for(int j = 2 * i; j < n; j += i) sieve[j] = 1;
            }
        }
        
        return count;
    }
};