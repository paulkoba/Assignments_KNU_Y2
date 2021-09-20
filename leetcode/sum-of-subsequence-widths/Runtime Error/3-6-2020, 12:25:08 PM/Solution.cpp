// https://leetcode.com/problems/sum-of-subsequence-widths

//pow(a, b) % c.
int modularPower(int a, int b, int c) {
    int output = 1;
    a = a % c;
    while (b > 0) {  
        if (b & 1) output = (output * a) % c;  
        b = b >> 1;
        a = (a * a) % c;
    }
    return output;
}

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        
        int output = 0;
        size_t sz = A.size();
        
        for(size_t i = 0; i < sz; ++i) {
            int temp = 0;
            temp -= modularPower(2, sz - i - 1, (int)1E9 + 7);
            temp += modularPower(2, i, (int)1E9 + 7);
            temp %= (int)1E9 + 7;
            temp *= A[i];
            output += temp % ((int)1E9 + 7);
        }
        
        return output;
    }
};