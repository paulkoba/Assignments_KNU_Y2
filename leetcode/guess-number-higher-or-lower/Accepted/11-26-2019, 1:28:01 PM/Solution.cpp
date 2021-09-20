// https://leetcode.com/problems/guess-number-higher-or-lower

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        while(true) {
            int mid = mid = low + (n - low) / 2;
            int k = guess(mid);
            if(k == 0) return mid;
            
            if(k < 0) {
                n = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
};