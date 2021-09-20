// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
    int findPairZero(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums) ++m[i];
        int output = 0;
        for(const auto& a : m) output += a.second >= 2;
        return output;
    }
    
public:
    int findPairs(vector<int>& nums, int k) {
        if(k == 0) return findPairZero(nums);
        
        set<int> tmp = set(nums.begin(), nums.end());
        nums = vector(tmp.begin(), tmp.end());
        
        int output = 0;
        int j = 0;
        
        for(int i = 1; i < nums.size(); ++i) {
            while(j < i && nums[i] - nums[j] >= k) {
                if(nums[i] - nums[j] == k) ++output;
                ++j;
            }
        }
        
        return output;
    }
};