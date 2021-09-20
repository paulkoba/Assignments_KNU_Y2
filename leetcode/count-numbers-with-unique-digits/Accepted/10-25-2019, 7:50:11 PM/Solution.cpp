// https://leetcode.com/problems/count-numbers-with-unique-digits

static const vector<int> factorial = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10) return countNumbersWithUniqueDigits(10);
        if(n == 0) return 1;
        return 9 * factorial[9] / factorial[9 - n + 1] + countNumbersWithUniqueDigits(n - 1);
    }
};