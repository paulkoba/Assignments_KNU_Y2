// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int, greater<int>> maxQ;
        
        int startIdx = 0;
        int output = 0;
        for(int i = 0; i < nums.size(); ++i) {
            ++maxQ[nums[i]];
            
            while(maxQ.begin()->first - maxQ.rbegin()->first > limit && startIdx < i) {
                --maxQ[nums[startIdx]];
                
                if(maxQ[nums[startIdx]] <= 0) {
                    maxQ.erase(nums[startIdx]);
                }
                
                ++startIdx;
            }
            
            output = max(output, i - startIdx + 1);
        }
        
        return output;
    }
};