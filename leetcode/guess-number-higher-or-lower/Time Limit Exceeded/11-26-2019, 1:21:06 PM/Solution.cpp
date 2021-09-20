// https://leetcode.com/problems/guess-number-higher-or-lower

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 0, mid = n / 2;
        while(true) {
            int k = guess(mid);
            if(k == 0) return mid;
            
            if(k < 0) {
                n = mid;
                mid = (n + low) / 2;
            } else {
                low = mid;
                mid = (n + low) / 2;
            }
        }
    }
};