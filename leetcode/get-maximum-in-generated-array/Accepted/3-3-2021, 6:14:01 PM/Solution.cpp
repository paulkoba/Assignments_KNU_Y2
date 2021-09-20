// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> arr(n + 1, 0);
        
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        arr[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            if(i % 2 == 0) {
                arr[i] = arr[i / 2];
            } else {
                arr[i] = arr[i / 2] + arr[i / 2 + 1];
            }
        }
        
        return *max_element(arr.begin(), arr.end());
    }
};