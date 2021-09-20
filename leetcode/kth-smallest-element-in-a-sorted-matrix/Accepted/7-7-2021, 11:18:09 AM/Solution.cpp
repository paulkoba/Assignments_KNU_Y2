// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<>> heap;
        
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                heap.push(matrix[i][j]);
            }
        }
        
        for(int i = 1; i < k; ++i) heap.pop();
        return heap.top();
    }
};