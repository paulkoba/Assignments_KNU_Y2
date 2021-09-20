// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0, n = s.size();
        
        for(int i = 0; i < n; i += 2) {
            a += (s[i] == '0');
            b += (s[i] == '1');
        }
        
        for(int i = 1; i < n; i += 2) {
            a += (s[i] == '1');
            b += (s[i] == '0');
        }
        
        return max(a, b);
    }
};