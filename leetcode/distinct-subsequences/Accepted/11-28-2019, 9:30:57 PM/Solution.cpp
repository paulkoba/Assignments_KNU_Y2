// https://leetcode.com/problems/distinct-subsequences

struct pair_hash {
    size_t operator() (const pair<int, int>& a) const {
        return hash<int>()(a.first ^ a.second);
    }
};

unordered_map<pair<int, int>, int, pair_hash> cache;

int numDistinctInner(const string& s, const string& t, size_t sIndex = 0, size_t tIndex = 0) {
    size_t szS = s.size();
    size_t szT = t.size();
    
    if(szT == tIndex) return 1;
    auto it = cache.find(make_pair(sIndex, tIndex));
    if(it != cache.end()) return it->second;
    
    int output = 0;
    
    for(size_t i = sIndex; i < szS; ++i) {
        if(s[i] == t[tIndex]) output += numDistinctInner(s, t, i + 1, tIndex + 1);
    }

    return cache[make_pair(sIndex, tIndex)] = output;
}

class Solution {
public:
    int numDistinct(const string& s, const string& t) {
        cache.clear();
        return numDistinctInner(s, t);
    }
};