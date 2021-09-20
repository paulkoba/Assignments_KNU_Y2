// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> data;
        int n = matrix.size();
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(data.size() >= k) {
                    if(data.top() < matrix[i][j]) break;
                    data.pop();
                    data.push(matrix[i][j]);
                } else {
                    data.push(matrix[i][j]);
                }
            }
        }
        
        return data.top();
    }
};