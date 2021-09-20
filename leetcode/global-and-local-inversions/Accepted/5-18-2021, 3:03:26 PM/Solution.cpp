// https://leetcode.com/problems/global-and-local-inversions

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int maxIdx = 0;
        int nextBiggest = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(i - maxIdx >= 2 && nums[i] < nums[maxIdx]) return false;
            if(i - nextBiggest >= 2 && nums[i] < nums[nextBiggest]) return false;
            
            if(nums[i] > nums[maxIdx]) {
                nextBiggest = maxIdx;
                maxIdx = i;
                continue;
            } else if(nums[i] > nums[nextBiggest]) {
                nextBiggest = i;
            }
        }
        
        return true;
    }
};