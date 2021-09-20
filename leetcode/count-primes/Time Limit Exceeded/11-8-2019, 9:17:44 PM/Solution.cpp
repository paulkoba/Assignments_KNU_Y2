// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<int> t;
        for(int i = 2; i < n; ++i) {
            bool prime = true;
            for(int k : t) if(i % k == 0) {
                prime = false;
                break;
            }
            if(prime) t.push_back(i);
        }
        return t.size();
    }
};