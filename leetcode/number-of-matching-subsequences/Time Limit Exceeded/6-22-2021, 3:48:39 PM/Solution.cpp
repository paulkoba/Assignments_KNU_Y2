// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    bool isSubsequence(const string& s, const string& t) {
        if(s.size() > t.size()) return false;
        
        int i = 0;
        for(char ss : s) {
            bool flag = false;
            for(; i < t.size(); ++i) {
                if(t[i] == ss) {
                    flag = true;
                    ++i;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int output = 0;
        for(const string& str : words) 
            output += isSubsequence(str, s);
        
        return output;
    }
};