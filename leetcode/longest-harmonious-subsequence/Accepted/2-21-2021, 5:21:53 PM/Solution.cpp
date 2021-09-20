// https://leetcode.com/problems/longest-harmonious-subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums) ++m[i];
        int output = 0;
        for(int i : nums) output = max(output, m[i + 1] != 0 ? m[i] + m[i + 1] : 0);
        return output;
    }
};