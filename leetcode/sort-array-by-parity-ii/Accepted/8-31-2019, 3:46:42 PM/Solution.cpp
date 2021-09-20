// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(const vector<int>& A) {
        const int size = A.size();
        if(size == 0) return {};
        
        int oddIndex = 1;
        int evenIndex = 0;
        
        std::vector<int> output(size);
        
        for(int i : A) {
            if(i % 2 == 0) {
                output[evenIndex] = i;
                evenIndex += 2;
            } else {
                output[oddIndex] = i;
                oddIndex += 2;
            }
        }
        
        return std::move(output);
    }
};