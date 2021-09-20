// https://leetcode.com/problems/kth-largest-element-in-a-stream

struct compareMinHeap {
    bool operator() (int a, int b) {
        return a > b;
    }
};

class KthLargest {
private:
    priority_queue<int, vector<int>, compareMinHeap> data;
public:
    KthLargest(int k, vector<int>& nums) {
        data = priority_queue<int, vector<int>, compareMinHeap>(nums.begin(), nums.end());
        int rem = nums.size() - k;
        for(int i = 0; i < rem; ++i) data.pop();
    }
    
    int add(int val) {
        data.push(val);
        data.pop();
        return data.top();
    }
};