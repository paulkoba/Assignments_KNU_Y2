// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> a;
        for(char ch : text) ++a[ch];
        return min(a['b'], min(a['a'], min(a['n'], min(a['l'] / 2, a['o'] / 2))));
    }
};