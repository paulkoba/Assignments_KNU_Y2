// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sz = candidates.size();
        int nSubsets = pow(2, sz);
        set<vector<int>> output;
        int k = 0;
        
        for(int i = 0; i < nSubsets; ++i) {
            vector<int> nums(__builtin_popcount(i));
            int t = 0;
            for(int j = 0; j < sz; ++j) if(i >> j & 1) nums[t++] = candidates[j];
            if(accumulate(nums.begin(), nums.end(), 0) == target) output.insert(nums);
        }
        
        return vector(output.begin(), output.end());
    }
};