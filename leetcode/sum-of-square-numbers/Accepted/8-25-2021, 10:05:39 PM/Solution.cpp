// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        set<int> d;
        
        int64_t i = 0;
        while(i * i <= c) {
            d.insert(i * i);
            ++i;
        }
        
        int64_t j = 0;
        while(j * j <= c) {
            if(d.find(c - j * j) != d.end()) return true;
            ++j;
        }
        
        return false;
    }
};