// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(const vector<int>& A) {
        const size_t sz = A.size();
        vector<int> output(sz);
        int bg = 0, end = sz - 1;
        
        for(int i : A) {
            if(i % 2 == 0) {
                output[bg++] = i;
            } else {
                output[end--] = i;
            }
        }
        
        return move(output);
    }
};