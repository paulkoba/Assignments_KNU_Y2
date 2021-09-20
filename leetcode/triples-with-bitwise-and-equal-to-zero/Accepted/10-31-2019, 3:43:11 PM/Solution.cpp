// https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero

class Solution {
public:
    int countTriplets(const vector<int>& A) {
        int sz = A.size();
        int count = 0;
        unordered_map<int, int> pairs;
        
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz; ++j) {
                ++pairs[A[i] & A[j]];
            }
        }
        
        for(const auto& p : pairs) {
            for(int i = 0; i < sz; ++i) {
                if((p.first & A[i]) == 0) count += p.second;
            }
        }
        
        return count;
    }
};