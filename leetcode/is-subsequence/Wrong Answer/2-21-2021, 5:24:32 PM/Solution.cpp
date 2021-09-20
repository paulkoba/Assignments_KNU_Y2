// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(char ss : s) {
            bool flag = false;
            for(; i < t.size(); ++i) {
                if(t[i] == ss) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};