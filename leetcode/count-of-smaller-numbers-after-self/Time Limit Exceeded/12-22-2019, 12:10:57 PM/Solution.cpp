// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<pair<int, int>> pairs(sz);
        vector<int> output(sz);
        for(int i = 0; i < sz; ++i) pairs[i] = make_pair(nums[i], i);
        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());
        
        for(int i = 0; i < sz; ++i) {
            for(int j = i + 1; j < sz; ++j) {
                if(pairs[i].second < pairs[j].second) ++output[pairs[i].second];
            }    
        }
        
        return output;
    }
};