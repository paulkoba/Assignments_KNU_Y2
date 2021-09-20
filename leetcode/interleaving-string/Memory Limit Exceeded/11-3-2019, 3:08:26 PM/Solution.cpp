// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() == 0) return s2 == s3;
        if(s2.size() == 0) return s1 == s3;
        if(s1[0] == s3[0] && s2[0] == s3[0]) {
            return isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s2.substr(1), s1, s3.substr(1));
        }
        if(s1[0] == s3[0]) return isInterleave(s1.substr(1), s2, s3.substr(1));
        if(s2[0] == s3[0]) return isInterleave(s2.substr(1), s1, s3.substr(1));
        
        return false;                                                                                
    }
};