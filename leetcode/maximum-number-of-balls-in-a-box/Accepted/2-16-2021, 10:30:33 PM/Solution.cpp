// https://leetcode.com/problems/maximum-number-of-balls-in-a-box

class Solution {
public:
    int numBox(int a) {
        int out = 0;
        while(a) {
            out += a % 10;
            a /= 10;
        }
        return out;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        for(int i = lowLimit; i <= highLimit; ++i)  ++count[numBox(i)];
        int m = 0;
        for(const auto& i : count) m = max(i.second, m);
        return m;
    }
};