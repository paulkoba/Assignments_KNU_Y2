// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int c1 = 0;
        for(char ch : s) c1 += ch == 'I';
        
        vector<int> output(s.size() + 1);
        
        int currentLow = c1 - 1;
        int currentHigh = c1 + 1;
        output[s.size()] = c1;
        
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == 'I') {
                output[i] = currentLow--;
            } else {
                output[i] = currentHigh++;
            }
        }
        
        return output;
    }
};