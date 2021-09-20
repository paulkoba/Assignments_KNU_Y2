// https://leetcode.com/problems/longest-turbulent-subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        if(arr.size() == 2) return arr[0] == arr[1] ? 1 : 2;
        
        int currentCount = 2;
        int maxCount = 1;
        
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