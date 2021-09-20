// https://leetcode.com/problems/number-of-good-ways-to-split-a-string

class Solution {
public:
    int numSplits(string s) {
        int letters[26] = {};
        int current[26] = {};
        for(char ch : s) ++letters[ch - 'a'];
            
        int output = 0;
        
        for(char ch : s) {
            ++current[ch - 'a'];
            
            int balance = 0;
            
            for(int i = 0; i < 26; ++i) {
                balance += (letters[i] - current[i] == 0 && current[i] != 0);
                balance -= (letters[i] != 0 && current[i] == 0);
            }
            
            output += (balance == 0);
        }
        
        return output;
    }
};