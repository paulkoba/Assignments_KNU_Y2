// https://leetcode.com/problems/interleaving-string

class Solution {
    
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2> &pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };
    
    unordered_map<pair<size_t, size_t>, bool, pair_hash> result;
    
public:
    bool isInterleave(string s1, string s2, string s3, size_t i1 = 0, size_t i2 = 0, size_t i3 = 0) {
        size_t idx1 = i1, idx2 = i2;

        if(s1.size() + s2.size() != s3.size()) return false;
        
        if(result.find(make_pair(i1, i2)) != result.end()) return result[make_pair(i1, i2)];
        
        for(size_t i = i3; i < s3.size(); ++i) {
            if(s1[idx1] == s3[i] && s2[idx2] != s3[i]) {
                idx1++;
                continue;
            }
            
            if(s1[idx1] != s3[i] && s2[idx2] == s3[i]) {
                idx2++;
                continue;
            }
            
            if(s1[idx1] != s3[i] && s2[idx2] != s3[i]) {
                return result[make_pair(i1, i2)] = false;
            }
            
            return isInterleave(s1, s2, s3, i1 + 1, i2, i3 + 1) || isInterleave(s1, s2, s3, i1, i2 + 1, i3 + 1);
            
        }
                
        return true;
    }
};