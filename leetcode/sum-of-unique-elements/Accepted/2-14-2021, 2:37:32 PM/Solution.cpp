// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> a;
        for(int i : nums) ++a[i];
        int out = 0;
        for(const auto& i : a) out += (i.second == 1) ? i.first : 0;
        return out;
    }
};