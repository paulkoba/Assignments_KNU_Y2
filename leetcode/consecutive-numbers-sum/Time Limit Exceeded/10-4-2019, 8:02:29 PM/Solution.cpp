// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        size_t out = 0, low = 0, high = 0;
        
        while(high <= N) {
            size_t sum = (low + high) * (high - low + 1) / 2;
            if(sum > N) {
                ++low;
            } else if(sum < N) {
                ++high;
            } else {
                ++low;
                ++high;
                ++out;
            }
        }
        
        return out;
    }
};