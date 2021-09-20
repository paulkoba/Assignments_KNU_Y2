// https://leetcode.com/problems/merge-intervals

bool greaterVec(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        if(sz == 0) return intervals;        
        sort(intervals.begin(), intervals.end(), greaterVec);
        int pos = 0;
        vector<bool> inOut(sz);
        while(pos < sz - 1) {
            if(intervals[pos][1] >= intervals[pos + 1][0]) {
                intervals[pos + 1][1] = max(intervals[pos + 1][1], intervals[pos][1]);
                intervals[pos + 1][0] = min(intervals[pos + 1][0], intervals[pos][0]);
                inOut[pos] = false;
                inOut[pos + 1] = true;
            } else {
                inOut[pos] = true;
            }
            pos++;
        }
        inOut[sz - 1] = true;
        vector<vector<int>> output;
        for(int i = 0; i < sz; ++i) if(inOut[i]) output.push_back(intervals[i]);
        return output;
    }
};