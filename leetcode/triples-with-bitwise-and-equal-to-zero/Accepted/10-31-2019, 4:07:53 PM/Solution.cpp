// https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero

class Solution {
public:
    int countTriplets(const vector<int>& A) {
        int sz = A.size();
        int m[2 << 16] = {};

        for(int i = 0; i < sz; ++i) {
            ++m[A[i]];
            for(int j = i + 1; j < sz; ++j) {
                m[A[i] & A[j]] += 2;
            }
        }
        
        int count = m[0] * sz;
        
        for(int j = 0; j < sz; ++j) {            
            for(int i = 1; i < (2 << 16); ++i) {
                if((i & A[j]) == 0) count += m[i];
                else i += (A[j] & i) - 1;
            }
        }
        
        return count;
    }
};