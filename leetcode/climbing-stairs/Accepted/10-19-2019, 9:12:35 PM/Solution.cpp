// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int current = 1;
        
        for(int i = 0; i < (n - 1); ++i) {
            int next = prev + current;
            prev = current;
            current = next;
        }
        
        return current;
        
    }
};