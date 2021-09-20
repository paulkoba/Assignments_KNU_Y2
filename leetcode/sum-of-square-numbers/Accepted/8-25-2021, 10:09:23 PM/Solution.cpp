// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> d;
        d.reserve(sqrt(c) + 10);
        
        int64_t i = 0;
        while(i * i <= c) {
            d.push_back(i * i);
            ++i;
        }
        
        int64_t j = 0;
        while(j * j <= c) {
            if(binary_search(d.begin(), d.end(), c - j * j)) return true;
            ++j;
        }
        
        return false;
    }
};