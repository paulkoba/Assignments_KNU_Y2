// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
       	int out = 0;
        
        while (x != 0) {
            out *= 10;
            out += x % 10;
            x /= 10;
        }
        
        return out; 
    }
};