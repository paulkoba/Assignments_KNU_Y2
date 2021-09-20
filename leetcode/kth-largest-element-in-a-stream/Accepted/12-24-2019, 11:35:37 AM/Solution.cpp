// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> data;
    int k;
public:
    KthLargest(int _k, vector<int>& nums) : k(_k) {
        data = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        int rem = nums.size() - k;
        for(int i = 0; i < rem; ++i) data.pop();
    }
    
    int add(int val) {
        data.push(val);
        if(data.size() > k) data.pop();
        return data.top();
    }
};