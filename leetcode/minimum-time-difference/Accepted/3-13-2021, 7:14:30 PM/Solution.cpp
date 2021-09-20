// https://leetcode.com/problems/minimum-time-difference

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(const auto& str : timePoints) 
            time.push_back((str[0] - '0') * 600 + (str[1] - '0') * 60 + (str[3] - '0') * 10 + (str[4] - '0'));
        
        sort(time.begin(), time.end());
        
        int minDiff = numeric_limits<int>::max();
        for(int i = 1; i < time.size(); ++i) minDiff = min(minDiff, time[i] - time[i - 1]);
        
        if(time.size() != 0) minDiff = min(minDiff, 1440 - *time.rbegin() + time[0]);
        
        return minDiff;
    }
};