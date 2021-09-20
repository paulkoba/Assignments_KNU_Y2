// https://leetcode.com/problems/maximum-69-number

class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        
        int last6position = -1;
        int currentPosition = 0;
        while(temp != 0) {
            if(temp % 10 == 6) {
                last6position = currentPosition;
            }
            ++currentPosition;
            temp /= 10;
        }
        
        if(last6position == -1) return num;
        
        return num + 3 * pow(10, last6position);
    }
};