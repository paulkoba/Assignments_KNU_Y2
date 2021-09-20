// https://leetcode.com/problems/check-if-a-string-can-break-another-string

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int counts[27] = {};
        
        for(int i = 0; i < s1.size(); ++i) {
            ++counts[s1[i] - 'a' + 1];
            --counts[s2[i] - 'a' + 1];
        }
        
        int countsCopy[27];
        
        for(int i = 0; i < 27; ++i) countsCopy[i] = -counts[i];
        
        bool flag = true;
        
        for(int i = 26; i > 0; --i) {
            if(counts[i] < 0) {
                flag = false;
                break;
            }
            counts[i - 1] += counts[i];
        }
        
        if(flag) return true;
        
        for(int i = 26; i > 0; --i) {
            if(countsCopy[i] < 0) return false;
            countsCopy[i - 1] += countsCopy[i];
        }
        
        return true;
    }
};