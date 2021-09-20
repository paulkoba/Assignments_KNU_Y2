// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> sorted;
        
        for(int i = 0; i < nums.size(); ++i) {
            sorted.push_back({nums[i], i});
        }
        
        sort(sorted.begin(), sorted.end());
        
        int last = nums.size() - 1;
        
        for(int i = 0; i < nums.size(); ++i) {
            while(sorted[last].first + sorted[i].first > target) {
                --last;
            }
            
            if(sorted[last].first + sorted[i].first == target) {
                return {sorted[i].second, sorted[last].second};
            }
        }
        
        return {-1, -1};
    }
};