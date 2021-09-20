// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        string output;
        for(int i = 0; i < s.size(); ++i) {
            string current;
            int j = 0;
            for(; j <= i && j + i < s.size(); ++j) {
                if(s[i - j] != s[i + j]) {
                    current = s.substr(i - (j - 1), 2 * (j - 1) + 1);
                    break;
                }
            }
            
            if(current == "") current = s.substr(i - (j - 1), 2 * (j - 1) + 1);
            
            output = current.size() > output.size() ? current : output;
        }
        
        for(int i = 0; i < s.size(); ++i) {
            string current;
            int j = 0;
            for(; j <= i && j + i + 1 < s.size(); ++j) {
                if(s[i - j] != s[i + j + 1]) {
                    current = s.substr(i - (j - 1), 2 * (j - 1) + 2);
                    break;
                }
            }
            
            if(current == "") current = s.substr(i - (j - 1), 2 * (j - 1) + 2);
            
            output = current.size() > output.size() ? current : output;
        }
        
        return output;
    }
};