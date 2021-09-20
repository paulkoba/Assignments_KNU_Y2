// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int output = 0;
        for(int i = 1; i < sqrt(2 * N); ++i) {
            if((N - (i - 1) * i / 2) % i == 0) output++;
        }
        return output;
    }
};