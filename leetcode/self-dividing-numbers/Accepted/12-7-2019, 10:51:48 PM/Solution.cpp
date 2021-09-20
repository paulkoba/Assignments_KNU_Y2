// https://leetcode.com/problems/self-dividing-numbers

inline bool selfDividing(int k) {
    int temp = k;
    while(k) {
        auto t = k % 10;
        if(t == 0) return false;
        if(temp % t != 0) return false;
        k /= 10;
    }
    
    return true;
}

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> output;
        for(size_t i = left; i <= right; ++i) if(selfDividing(i)) output.push_back(i);
        return output;
    }
};