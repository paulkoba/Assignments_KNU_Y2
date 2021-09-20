// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxQueue(nums.begin(), nums.end());
        
        int result = maxQueue.top() - 1;
        maxQueue.pop();
        result *= maxQueue.top() - 1;
        
        return result;
    }
};