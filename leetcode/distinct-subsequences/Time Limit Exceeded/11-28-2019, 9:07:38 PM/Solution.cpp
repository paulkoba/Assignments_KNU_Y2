// https://leetcode.com/problems/distinct-subsequences

int numDistinctInner(const string& s, const string& t, size_t sIndex = 0, size_t tIndex = 0) {
    size_t szS = s.size();
    size_t szT = t.size();
    
    if(szT == tIndex) return 1;
    
    int output = 0;
    
    for(size_t i = sIndex; i < szS; ++i) {
        if(s[i] == t[tIndex]) output += numDistinctInner(s, t, i + 1, tIndex + 1);
    }

    return output;
}

class Solution {
public:
    int numDistinct(const string& s, const string& t) {
        return numDistinctInner(s, t);
    }
};