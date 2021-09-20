// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k >= 2) {
            sort(s.begin(), s.end());
            return s;
        }
        
        string res = s;
        for(int i = 0; i < s.size(); ++i) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            s2 += s1;
            
            if(s2 < res) res = s2;
        }
        
        return res;
    }
};