// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
    bool isSubsequence(const string& s, const string& t) {
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
    
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int output = 0;
        for(const string& s : words) output += isSubsequence(s, S);
        return output;
    }
};