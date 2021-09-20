// https://leetcode.com/problems/longest-common-subsequence

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class Solution {
public:    
    int lcs(string text1, string text2, int m, int n, unordered_map<pair<int, int>, int, pair_hash>& cache) {
        if(m == 0 || n == 0) return 0;
        if(cache.find({m, n}) != cache.end()) return cache[{m, n}];
        
        if(text1[m - 1] == text2[n - 1]) return cache[{m - 1, n - 1}] = 1 + lcs(text1, text2, m - 1, n - 1, cache);
        
        return max(cache[{m - 1, n}] = lcs(text1, text2, m - 1, n, cache), cache[{m, n - 1}] = lcs(text1, text2, m, n - 1, cache));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        unordered_map<pair<int, int>, int, pair_hash> cache;
        
        return lcs(text1, text2, text1.size(), text2.size(), cache);
    }
};