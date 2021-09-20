// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        
        int64_t t0 = 1, t1 = 1, t2 = 0;
        for(int i = 0; i < (n - 2); ++i) {
            int64_t next = t0 + t1 + t2;
            t2 = t1;
            t1 = t0;
            t0 = next;
        }
        return t0;
    }
};