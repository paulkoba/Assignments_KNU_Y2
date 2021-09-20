// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int temp = n;
        int sum = 0;
        while(n != 0) {
            sum += n % 10;
            n /= 10;
        }
        n = temp;
        
        int prod = 1;
        while(n != 0) {
            prod *= n % 10;
            n /= 10;
        }
        
        return prod - sum;
    }
};