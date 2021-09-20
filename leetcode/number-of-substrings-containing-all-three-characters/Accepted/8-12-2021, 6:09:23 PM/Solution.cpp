// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int counts[3] = {};
        int output = 0;
        int k = 0;
        
        for(int i = 0; i < s.size(); ++i) {
            ++counts[s[i] - 'a'];
            
            while(counts[0] && counts[1] && counts[2]) {
                --counts[s[k] - 'a'];
                ++k;
            }
            
            output += k;
        }
        
        return output;
    }
};