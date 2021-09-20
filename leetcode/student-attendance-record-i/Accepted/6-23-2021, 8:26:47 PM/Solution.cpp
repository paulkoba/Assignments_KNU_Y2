// https://leetcode.com/problems/student-attendance-record-i

class Solution {
public:
    bool checkRecord(string s) {        
        for(int i = 2; i < s.size(); ++i) {
            if(s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L') {
                return false;
            }
        }
        
        bool absent = false;
        
        for(char ch : s) {
            if(ch == 'A') {
                if(absent) return false;
                absent = true;
            }
        }
        
        return true;
    }
};