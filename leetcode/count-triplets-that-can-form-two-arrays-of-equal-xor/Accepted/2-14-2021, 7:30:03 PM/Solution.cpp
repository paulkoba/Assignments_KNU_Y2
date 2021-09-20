// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int output = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            int xor1 = arr[i];
            for(int j = i + 1; j < arr.size(); ++j) {
                xor1 ^= arr[j];
                if(xor1 == 0) output += j - i;
            }
        }
        
        return output;
    }
};