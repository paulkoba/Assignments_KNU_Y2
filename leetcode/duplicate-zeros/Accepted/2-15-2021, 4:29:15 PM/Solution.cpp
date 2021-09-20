// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int intSize = arr.size();
        
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] == 0) {
                arr.insert(arr.begin() + i, 0);
                ++i;
            }
        }
        
        arr.resize(intSize);
    }
};