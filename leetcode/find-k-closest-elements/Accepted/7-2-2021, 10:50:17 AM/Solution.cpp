// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> closestHeap;
        
        for(int el : arr) closestHeap.push({abs(el - x), el});
        
        vector<int> output;
        for(int i = 0; i < k; ++i) {
            output.push_back(closestHeap.top().second);
            closestHeap.pop();
        }
        
        sort(output.begin(), output.end());
        
        return output;
    }
};