// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> AB_sum;
        for(int a : A)
            for(int b : B)
                ++AB_sum[a + b];
        
        int count = 0;
        const auto k = AB_sum.end(); 
        for(int c : C)
            for(int d : D) {
                const auto it = AB_sum.find(-c - d);
                if(it != k) count += it->second;
            }
        
        return count;
    }
};