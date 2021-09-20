// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int out = 0;
        for(const auto& a : accounts) {
            out = max(out, accumulate(a.begin(), a.end(), 0));
        }
        
        return out;
    }
};