// https://leetcode.com/problems/decode-ways

class Solution {
    unordered_map<int, int> memo;
public:
    int numDecodings(string s, int i = 0) {
        if(i >= s.size()) return memo[i] = 1;
        if(s[i] == '0') return memo[i] = 0;
        if(i < s.size() - 1) {
            if(s[i] == '1') {
                return memo[i] = numDecodings(s, i + 1) + numDecodings(s, i + 2);
            }
            
            if(s[i] == '2' && s[i] <= '6') {
                return memo[i] = numDecodings(s, i + 1) + numDecodings(s, i + 2);
            }
            
            return memo[i] = numDecodings(s, i + 1);
        } else {
            return memo[i] = numDecodings(s, i + 1);
        }
    }
};