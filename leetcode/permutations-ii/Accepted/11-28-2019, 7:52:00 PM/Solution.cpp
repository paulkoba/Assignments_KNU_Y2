// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        
        do {
            output.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        
        return output;
    }
};