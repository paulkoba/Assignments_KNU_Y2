// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> pairs(60);
        for(int a : time) ++pairs[a % 60];
        int output = pairs[0] * (pairs[0] - 1) / 2;
        for(int i = 1; i < 30; ++i) output += pairs[i] * pairs[60 - i];
        output += pairs[30] * (pairs[30] - 1) / 2;
        return output;
    }
};