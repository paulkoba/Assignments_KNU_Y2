// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> output(n, 0);
                
        for(int i = 1; i < n; i += 2) output[i] = -i;
        for(int i = 0; i < n - 1; i += 2) output[i] = i + 1;
        
        return output;
    }
};