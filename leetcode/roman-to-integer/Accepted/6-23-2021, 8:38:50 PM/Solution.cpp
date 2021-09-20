// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        char count[256] = {};
        
        for(char ch : s) ++count[ch];
        
        int result = 0;
        
        for(char ch : s) {
            --count[ch];
            
            if(ch == 'I') {
                if(count['V'] || count['X']) {
                    --result;
                } else {
                    ++result;
                }
            }
            
            if(ch == 'X') {
                if(count['L'] || count['C']) {
                    result -= 10;
                } else {
                    result += 10;
                }
            }
            
            if(ch == 'C') {
                if(count['D'] || count['M']) {
                    result -= 100;
                } else {
                    result += 100;
                }
            }
            
            if(ch == 'V') result += 5;
            if(ch == 'M') result += 1000;
            if(ch == 'D') result += 500;
            if(ch == 'L') result += 50;
        }
        
        return result;
    }
};