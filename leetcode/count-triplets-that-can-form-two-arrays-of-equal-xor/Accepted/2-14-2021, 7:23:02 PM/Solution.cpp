// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            for(int j = i + 1; j < arr.size(); ++j) {
                int xor1 = 0;
                for(int p = i; p < j; ++p) xor1 ^= arr[p];
                
                int xor2 = 0;
                
                for(int k = j; k < arr.size(); ++k) {
                    xor2 ^= arr[k];
                    count += xor2 == xor1;
                }
            }
        }
        return count;
    }
};