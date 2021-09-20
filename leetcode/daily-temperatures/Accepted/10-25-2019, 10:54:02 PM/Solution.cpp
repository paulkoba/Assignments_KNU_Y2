// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int sz = T.size();
        vector<int> output(sz);
        stack<pair<int, int>> waiting; //Temperature and index stored.
        for(int i = 0; i < sz; ++i) {
            while(!waiting.empty() && waiting.top().first < T[i]) {
                auto tmp = waiting.top();
                waiting.pop();
                output[tmp.second] = i - tmp.second;
            }
            waiting.push(make_pair(T[i], i));
        }
        return output;
    }
};