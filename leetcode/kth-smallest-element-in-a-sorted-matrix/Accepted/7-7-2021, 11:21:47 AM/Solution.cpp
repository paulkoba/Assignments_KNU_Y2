// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> heap;
        
        int sz = matrix.size(), sz1 = matrix[0].size();
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz1; ++j) {
                heap.push(matrix[i][j]);
            }
        }
        
        while(heap.size() > k) heap.pop();
        return heap.top();
    }
};