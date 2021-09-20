// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count = 0;
        for(char ch : s) count += ch == '1';
        int sz = s.size();
        
        int result = count;
        int current = result;
        
        for(int i = sz - 1; i >= 0; --i) {
            if(s[i] == '0') {
                ++current;
            } else {
                --current;
            }
            
            result = min(current, result);
        }
        
        return result;
    }
};