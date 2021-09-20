// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int mask = 0;
        set<vector<int>> output;
        
        while(mask < (1 << nums.size())) {
            vector<int> current;
            
            for(int i = 0; i < nums.size(); ++i) {
                if(mask & (1 << i)) current.push_back(nums[i]);
            }
            
            sort(current.begin(), current.end());
            
            output.insert(current);
            
            ++mask;
        }
        
        return vector<vector<int>>(output.begin(), output.end());
    }
};