// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(const vector<int>& A) {
        const int size = A.size();
        if(size == 0) return {};
        
        int oddIndex = 1;
        int evenIndex = 0;
        
        std::vector<int> output(size);
        
        auto end = A.end();
        for(auto iter = A.begin(); iter < end; ++iter) {
            if(*iter % 2 == 0) {
                output[evenIndex] = *iter;
                evenIndex += 2;
            } else {
                output[oddIndex] = *iter;
                oddIndex += 2;
            }
        }
        
        return std::move(output);
    }
};