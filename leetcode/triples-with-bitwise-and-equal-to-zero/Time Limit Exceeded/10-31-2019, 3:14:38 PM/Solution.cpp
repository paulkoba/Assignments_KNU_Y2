// https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int sz = A.size();
        int count = 0;
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz; ++j) {
                int t = A[i] & A[j];
                for(int k = 0; k < sz; ++k) {
                    count += (t & A[k]) == 0;
                }
            }
        }
        return count;
    }
};