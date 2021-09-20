// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xorLeft(n, 0);        
        xorLeft[0] = arr[0];
        for(int i = 1; i < n; ++i) {
            xorLeft[i] = arr[i] ^ xorLeft[i - 1];
        }
        
        vector<int> output;
        
        for(const auto& query : queries) {
            output.push_back((query[0] - 1 >= 0 ? xorLeft[query[0] - 1] : 0) ^ xorLeft[query[1]]);
        }
        
        return output;
    }
};