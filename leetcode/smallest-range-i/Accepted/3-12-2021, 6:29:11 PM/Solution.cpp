// https://leetcode.com/problems/smallest-range-i

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        return max(0, *max_element(A.begin(), A.end()) - *max_element(A.begin(), A.end(), greater<int>()) - 2 * K);
    }
};