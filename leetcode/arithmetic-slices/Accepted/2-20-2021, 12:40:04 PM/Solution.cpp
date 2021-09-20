// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sliceStart = 0;
        int output = 0;
        for(int i = 2; i < A.size(); ++i) {
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                output += (i - sliceStart - 1);
            } else {
                sliceStart = i - 1;
            }
        }
        
        return output;
    }
};