// https://leetcode.com/problems/unique-binary-search-trees

unordered_map<int, int> memo;

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(memo[n] != 0) return memo[n];
        
        int output = 0;
        for(int i = 0; i < n; ++i) {
            output += numTrees(n - i - 1) * numTrees(i);
        }
        return memo[n] = output;
    }
};