// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& input) {
        sort(input.begin(), input.end());
        
        int sz = input.size();
        int nSubsets = pow(2, sz);
        vector<vector<int>> output(nSubsets);
        int k = 0;
        
        for(int i = 0; i < nSubsets; ++i) {
            vector<int> nums(__builtin_popcount(i));
            int t = 0;
            for(int j = 0; j < sz; ++j) if(i >> j & 1) nums[t++] = input[j];
            output[k++] = nums;
        }
        
        return output;
    }
};