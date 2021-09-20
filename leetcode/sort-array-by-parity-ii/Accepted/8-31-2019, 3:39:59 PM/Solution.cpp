// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int size = A.size();
        if(size == 0) return {};
        
        int oddIndex = 1;
        int evenIndex = 0;
        
        std::vector<int> output(size);
        
        for(int i = 0; i < size; i++) {
            if(A[i] % 2 == 0) {
                output[evenIndex] = A[i];
                evenIndex += 2;
            } else {
                output[oddIndex] = A[i];
                oddIndex += 2;
            }
        }
        
        return output;
    }
};