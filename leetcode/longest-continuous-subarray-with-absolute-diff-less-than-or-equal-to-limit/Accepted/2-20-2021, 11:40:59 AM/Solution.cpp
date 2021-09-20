// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int, greater<int>> maxQ;
        map<int, int> minQ;
        
        int startIdx = 0;
        int output = 0;
        for(int i = 0; i < nums.size(); ++i) {
            ++minQ[nums[i]];
            ++maxQ[nums[i]];
            
            while(maxQ.begin()->first - minQ.begin()->first > limit && startIdx < i) {
                --minQ[nums[startIdx]];
                --maxQ[nums[startIdx]];
                
                if(minQ[nums[startIdx]] <= 0) {
                    minQ.erase(nums[startIdx]);
                    maxQ.erase(nums[startIdx]);
                }
                
                ++startIdx;
            }
            
            output = max(output, i - startIdx + 1);
        }
        
        return output;
    }
};