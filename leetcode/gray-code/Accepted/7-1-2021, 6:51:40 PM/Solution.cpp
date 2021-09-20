// https://leetcode.com/problems/gray-code

class Solution {
public:    
    void generate(vector<int>& output, int n, int& el) {
        if(n == 0) {
            output.push_back(el);
            return;
        }
        
        generate(output, n - 1, el);
        el ^= 1 << (n - 1);
        generate(output, n - 1, el);
    }
    
    vector<int> grayCode(int n) {
        vector<int> output;
        int tempRef = 0;
        generate(output, n, tempRef);
        
        return output;
    }
};