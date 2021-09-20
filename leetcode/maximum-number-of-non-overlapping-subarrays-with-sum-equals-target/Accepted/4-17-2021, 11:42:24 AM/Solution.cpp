// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        set<int> prefixSumSeen;
        prefixSumSeen.insert(0);
        int currentSum = 0;
        int output = 0;
        for(int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            if(prefixSumSeen.find(currentSum - target) != prefixSumSeen.end()) {
                prefixSumSeen.clear();
                prefixSumSeen.insert(0);
                ++output;
                currentSum = 0;
            } else {
                prefixSumSeen.insert(currentSum);
            }
        }
        
        return output;
    }
};