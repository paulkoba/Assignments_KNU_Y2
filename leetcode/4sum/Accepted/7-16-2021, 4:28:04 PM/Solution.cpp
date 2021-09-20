// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> output;
        int sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            for(int j = i + 1; j < sz; ++j) {
                int last = sz - 1;
                for(int k = j + 1; k < sz; ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    while(last > k && sum + nums[last] > target) --last;
                    while(last > k && sum + nums[last] == target) {
                        output.insert({nums[i], nums[j], nums[k], nums[last]});
                        --last;
                    }
                }
            }
        }
        
        return vector(output.begin(), output.end());
    }
};