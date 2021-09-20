// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> test;
        for(int i : nums) ++test[i];
        return test.size() != nums.size();
    }
};