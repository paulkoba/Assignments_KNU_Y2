// https://leetcode.com/problems/ways-to-make-a-fair-array

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd = 0, even = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            odd += nums[i];
        }
        
        for(int i = 1; i < nums.size(); i += 2) {
            even += nums[i];
        }
        
        int currentOdd = 0, currentEven = 0;
        
        int count = 0, temp = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(i % 2 == 0) {
                currentEven += temp;
                odd -= nums[i];
            } else {
                currentOdd += temp;
                even -= nums[i];
            }
            
            if(currentOdd + even == currentEven + odd) ++count;
            
            temp = nums[i];
        }
        
        return count;
    }
};