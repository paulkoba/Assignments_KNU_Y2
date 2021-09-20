// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int output = 0;
        for(int i : nums) {
            while(i >= 10) {
                i /= 100;
            }
            if(i == 0) ++output;
        }
        return output;
    }
};