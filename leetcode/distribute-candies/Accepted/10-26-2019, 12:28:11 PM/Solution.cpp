// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> lengths;
        for(int i : candies) lengths[i]++;
        return min(lengths.size(), candies.size() / 2);
    }
};