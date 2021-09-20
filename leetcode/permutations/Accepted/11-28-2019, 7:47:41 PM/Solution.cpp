// https://leetcode.com/problems/permutations

size_t factorial(size_t n) {
    return n <= 1 ? 1 : factorial(n - 1) * n;
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output(factorial(nums.size()));
        
        int k = 0;
        
        do {
            output[k++] = nums;
        } while(next_permutation(nums.begin(), nums.end()));
        
        return output;
    }
};