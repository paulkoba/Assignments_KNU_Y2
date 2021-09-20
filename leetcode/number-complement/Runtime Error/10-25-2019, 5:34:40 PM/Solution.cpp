// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        int count = 0;
        int temp = num;
        while(temp) {
            temp = temp >> 1;
            ++count;
        }
        return ((int)pow(2, count) - 1) ^ num;
    }
};