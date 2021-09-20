// https://leetcode.com/problems/sliding-window-maximum

#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> window;
        vector<int> output; 
        int i = 0;
        int maximum = std::numeric_limits<int>::min();
        
        for(; i < k; ++i) {
            ++window[nums[i]];
            maximum = max(maximum, nums[i]);
        }
        
        output.push_back(maximum);
        
        for(; i < nums.size(); ++i) {
            --window[nums[i - k]];
            ++window[nums[i]];
            if(window[nums[i - k]] == 0) window.erase(nums[i - k]);
            output.push_back((--window.end())->first);
        }
        
        return output;
    }
};