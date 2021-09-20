// https://leetcode.com/problems/binary-watch

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> output;
        for(int i = 0; i < 720; ++i) {
            int hour = i / 60;
            int minute = i % 60;
            if(__builtin_popcount(hour) + __builtin_popcount(minute) == num) {
                output.push_back(to_string(hour).append(":").append(minute >= 10 ? "" : "0").append(to_string(minute)));
            }
        }
        
        return output;
    }
};