// https://leetcode.com/problems/implement-rand10-using-rand7

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = rand7() - 1;
        int b = 0;
        int r = 40;
        while(r > 39) {
            b = a;
            a = rand7() - 1;
            r = a * 7 + b;
        }
        return r % 10 + 1;
    }
};