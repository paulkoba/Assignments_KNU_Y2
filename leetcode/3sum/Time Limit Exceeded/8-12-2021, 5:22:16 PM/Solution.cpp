// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        
        set<vector<int>> output;
        
        for(int i = 0; i < sz; ++i) {
            int k = sz - 1;
            
            for(int j = i + 1; j < sz; ++j) {
                while(k > j && nums[k] + nums[i] + nums[j] > 0) --k;
                if(k > j && nums[k] + nums[i] + nums[j] == 0) {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    sort(v.begin(), v.end());
                    
                    output.insert(v);
                }
            }
        }
        
        return vector<vector<int>>(output.begin(), output.end());
    }
};