// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A.size() == 0) return true;
        
        for(int i = 0; i < A.size(); ++i) {
            if(A.substr(i + 1) + A.substr(0, i + 1) == B) return true;
        }
        
        return false;
    }
};