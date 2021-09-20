// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
       	int64_t out = 0;
        
        while (x != 0) {
            out *= 10;
            out += x % 10;
            x /= 10;
        }
        
        if((out <= -pow(2, 31)) || (out >= pow(2, 31) - 1)) return 0;
        
        return out; 
    }
};