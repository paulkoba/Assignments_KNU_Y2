// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        for(int i = 0; i < sz; ++i) {
            if(arr[i] == numeric_limits<int>::min()) continue;
            if(arr[i] < 0) {
                if(arr[i] % 2 == 1) return false;
                auto iter = find(arr.begin(), arr.end(), arr[i] / 2);
                if(iter == arr.end()) return false;
                *iter = numeric_limits<int>::min();
            } else {
                auto iter = find(arr.begin(), arr.end(), arr[i] * 2);
                if(iter == arr.end()) return false;
                *iter = numeric_limits<int>::min();
            }
            arr[i] = numeric_limits<int>::min();
        }
        
        return true;
    }
};