// https://leetcode.com/problems/implement-rand10-using-rand7

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:    
    int rand10() {
        int result = 100;
        
        while(result > 40) {
            result = ((rand7() - 1) * 7) + rand7();
        }
        
        return ((result - 1) % 10) + 1;
    }
};