// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> data(nums.begin(), nums.end());
        for(int i = 1; i < k; ++i) {
            data.pop();
        }
        return data.top();
    }
};