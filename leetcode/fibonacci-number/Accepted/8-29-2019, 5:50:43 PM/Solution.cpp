// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        
        int prev = 1;
        int current = 1;
        
        for(int i = 0; i < (n - 2); ++i) {
            int next = prev + current;
            prev = current;
            current = next;
        }
        
        return current;
    }
};