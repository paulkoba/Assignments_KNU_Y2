// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<int> output(sz);
        multiset<int> sorted;
        for(int i = sz - 1; i >= 0; --i) {
            sorted.insert(nums[i]);
            output[i] = distance(sorted.begin(), lower_bound(sorted.begin(), sorted.end(), nums[i]));
        }
        return output;
    }
};