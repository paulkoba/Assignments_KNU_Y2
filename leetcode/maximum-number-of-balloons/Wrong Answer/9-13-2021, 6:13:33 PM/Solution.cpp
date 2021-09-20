// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        char counts[26] = {};
        for(char ch : text) counts[ch - 'a']++;
        
        int a = counts[0];
        int b = counts[1];
        int c = counts['l' - 'a'];
        int d = counts['o' - 'a'] / 2;
        int e = counts['n' - 'a'];
        
        return min(a, min(b, min(c, min(d,e))));
    }
};