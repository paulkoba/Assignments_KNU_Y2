// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int sz = A.size();
        int left = 0, right = sz - 1, ptr = sz - 1;
        vector<int> out(sz);
        while(left <= right) {
            if(abs(A[left]) > abs(A[right])) {
                out[ptr--] = pow(A[left++], 2);
            } else {
                out[ptr--] = pow(A[right--], 2);
            }
        }
        return out;
    }
};