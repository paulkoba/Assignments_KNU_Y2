// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int output = 0;
        for(int i : nums) {
            output += count[i];
            ++count[i];
        }
        return output;
    }
};