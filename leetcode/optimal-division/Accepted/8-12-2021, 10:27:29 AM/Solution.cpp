// https://leetcode.com/problems/optimal-division

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size() == 1) return to_string(nums[0]);
        if(nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string output = to_string(nums[0]);
        output.append("/(");
        for(int i = 1; i < nums.size(); ++i) {
            output.append(to_string(nums[i]));
            output.append(1, '/');
        }
        output.pop_back();
        output.append(1, ')');
        
        return output;
    }
};