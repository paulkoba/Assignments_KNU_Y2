// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [] (int a, int b) {
            if(__builtin_popcount(a) == __builtin_popcount(b)) return a < b;
            return __builtin_popcount(a) < __builtin_popcount(b);
        });
        return arr;
    }
};