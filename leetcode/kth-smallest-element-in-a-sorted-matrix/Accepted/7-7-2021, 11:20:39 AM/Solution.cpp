// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<>> heap;
        int sz = matrix.size(), sz1 = matrix[0].size();
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz1; ++j) {
                heap.push(matrix[i][j]);
            }
        }
        
        for(int i = 1; i < k; ++i) heap.pop();
        return heap.top();
    }
};