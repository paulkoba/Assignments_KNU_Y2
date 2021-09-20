// https://leetcode.com/problems/prime-arrangements

class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<int> sieve(n + 1);
        
        sieve[0] = 1;
        sieve[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            if(sieve[i] == 0) {
                for(int j = i * 2; j <= n; j += i) {
                    sieve[j] = 1;
                } 
            }
        }
        
        int count = 0;
        
        for(int i = 0; i <= n; ++i) 
            if(sieve[i] == 0) ++count;
        
        uint64_t output = 1;
        
        for(int i = 1; i <= count; ++i) {
            output = output * i;
            output %= 1000000007;
        }
        
        count = n - count;
        
        for(int i = 1; i <= count; ++i) {
            output = output * i;
            output %= 1000000007;
        }
        
        return output;
    }
};