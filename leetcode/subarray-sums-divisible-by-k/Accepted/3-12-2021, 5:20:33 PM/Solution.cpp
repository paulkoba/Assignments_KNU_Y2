// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> cache(K, 0);
        cache[0] = 1;
        int sum = 0;
        int output = 0;
        for(int i = 0; i < A.size(); ++i) {
            sum += A[i];
            int mod = (K + sum % K) % K;
            output += cache[mod];
            cache[mod]++;
        }
        
        return output;
    }
};