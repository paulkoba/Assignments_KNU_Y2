// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        
        A += A;
        return A.find(B) != string::npos;
    }
};