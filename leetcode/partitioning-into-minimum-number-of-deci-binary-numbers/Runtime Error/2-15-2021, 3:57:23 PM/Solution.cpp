// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int res = stoi(n);
        int maxDigit = 0;
        
        while(res != 0) {
            maxDigit = max(maxDigit, res % 10);
            res /= 10;
        }
        
        return maxDigit;
    }
};