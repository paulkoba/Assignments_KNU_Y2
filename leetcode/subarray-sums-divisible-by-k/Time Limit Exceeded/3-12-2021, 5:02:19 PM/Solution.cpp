// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int out = 0;
        for(int i = 0; i < A.size(); ++i) {
            int sum = 0;
            for(int j = i; j < A.size(); ++j) {
                sum += A[j];
                if(sum % K == 0) ++out;
            }
        }
        return out;
    }
};