// https://leetcode.com/problems/longest-turbulent-subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() <= 2) return arr.size();
        
        int currentCount = 2;
        int maxCount = 2;
        
        for(int i = 2; i < arr.size(); ++i) {
            if((arr[i] > arr[i - 1] ) ^ (arr[i - 1] > arr[i - 2])) {
                ++currentCount;
            } else {
                currentCount = 2;
            }
            if(arr[i] == arr[i - 1]) currentCount = 1;
            maxCount = max(currentCount, maxCount);
        }
        
        return maxCount;
    }
};