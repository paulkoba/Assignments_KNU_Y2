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
        int lOut = 0;
        vector<char> inOut(sz);
        while(pos < sz - 1) {
            if(intervals[pos][1] >= intervals[pos + 1][0]) {
                intervals[pos + 1][1] = max(intervals[pos + 1][1], intervals[pos][1]);
                intervals[pos + 1][0] = min(intervals[pos + 1][0], intervals[pos][0]);
                inOut[pos] = 0;
            } else {
                inOut[pos] = 1;
            }
            lOut += inOut[pos];
            pos++;
        }
        inOut[sz - 1] = true;
        vector<vector<int>> output(lOut + 1);
        for(int i = 0; i < sz; ++i) if(inOut[i]) output[lOut--] = intervals[i];
        return output;
    }
};