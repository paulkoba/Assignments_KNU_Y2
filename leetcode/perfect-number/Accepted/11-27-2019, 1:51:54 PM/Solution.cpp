// https://leetcode.com/problems/perfect-number

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int sum = 1;
        
        int tmpNum = sqrt(num);
        for(int i = 2; i <= tmpNum; ++i) {
            if(num % i == 0) {
                sum += i + num / i;
            }
        }
        
        return sum == num;
    }
};