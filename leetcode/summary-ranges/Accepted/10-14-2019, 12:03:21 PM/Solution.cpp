// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return {};
        int64_t begNum = nums[0];
        int64_t currNum = nums[0] + 1;
        
        vector<string> output;

        for(int64_t i = 1; i < sz; ++i) { 
            if(nums[i] == currNum) {
                ++currNum;
            } else {
                if((currNum - begNum) == 1) {
                    output.push_back(to_string(begNum));
                } else {
                    output.push_back(to_string(begNum).append("->").append(to_string(currNum - 1)));
                }
                begNum = nums[i];
                currNum = int64_t(nums[i]) + 1;
            }
        }
        
        if((currNum - begNum) == 1) {
            output.push_back(to_string(begNum));
        } else {
            output.push_back(to_string(begNum).append("->").append(to_string(currNum - 1)));
        }
        
        return output;
    }
};