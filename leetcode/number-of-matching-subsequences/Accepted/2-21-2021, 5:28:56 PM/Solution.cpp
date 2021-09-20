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
        unordered_map<string, int> ss;
        for(const string& s : words) ++ss[s];
        int output = 0;
        for(const auto& s : ss) output += isSubsequence(s.first, S) * s.second;
        return output;
    }
};