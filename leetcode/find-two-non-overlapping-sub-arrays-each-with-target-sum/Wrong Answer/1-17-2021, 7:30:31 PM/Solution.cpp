// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int length1 = arr.size();
        int length2 = arr.size();
        int current = 0;
        int currentLength = 0;
        int lower = 0;
        for(int i = 0; i < arr.size(); ++i) {
            current += arr[i];
            ++currentLength;
            if(current == target) {
                if(length1 > currentLength) {
                    length2 = length1;
                    length1 = currentLength;
                } else if(length2 > currentLength) {
                    length2 = currentLength;
                }
            }
            
            while(current > target) {
                current -= arr[lower++];
                --currentLength;
            }
        }
        
        if(length2 == arr.size()) return -1;
        
        return length1 + length2;
    }
};