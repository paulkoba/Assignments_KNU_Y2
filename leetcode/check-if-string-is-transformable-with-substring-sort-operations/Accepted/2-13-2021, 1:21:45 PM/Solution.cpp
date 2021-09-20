// https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations

class Solution {
public:
    bool isTransformable(string s, string t) {
        if(s.size() != t.size()) return false;
        
        for(int ch = 0; ch <= 9; ++ch) {
            int temp = 0;
            for(int i = 0; i < s.size(); ++i) {
                if(s[i] == ch + '0') ++temp;
                if(t[i] == ch + '0') --temp;
                
                if(temp > 0) return false;
            }
            
            s.erase(remove(s.begin(), s.end(), ch + '0'), s.end());
            t.erase(remove(t.begin(), t.end(), ch + '0'), t.end());
        }
        
        return true;
    }
};