// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> counts;
        int output = 0;
        for(char ch : stones) ++counts[ch];
        for(char ch : jewels) output += counts[ch];
        
        return output;
    }
};