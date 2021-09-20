// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        for(int i : nums) {
            minQ.push(i);
            maxQ.push(i);
        }
        
        vector<int> s;
        
        for(int i = 0; i < 4; ++i) {
            s.push_back(maxQ.top());
            s.push_back(minQ.top());
            minQ.pop();
            maxQ.pop();
        }
        
        sort(s.begin(), s.end());
        
        int minWindow = numeric_limits<int>::max();
        
        for(int i = 4; i < s.size(); ++i) {
            minWindow = min(s[i] - s[i - 4], minWindow);
        }
        
        return minWindow;
    }
};