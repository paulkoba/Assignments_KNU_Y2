// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int length = A.size();
                
        int low = 0;
        int high = length - 1;
        
        while(low < high) {
            int middle = (low + high) / 2;
            
            if(A[middle] < A[middle + 1]) {
                low = middle + 1;
            } else {
                high = middle;
            }
        }
        
        return low;
    }
};