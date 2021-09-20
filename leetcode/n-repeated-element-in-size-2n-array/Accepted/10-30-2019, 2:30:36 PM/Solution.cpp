// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> a;
        int sz = A.size() - 1;
        while(true) {
            ++a[A[sz]];
            if(a[A[sz]] > 1) return A[sz];
            --sz;
        } 
    }
};