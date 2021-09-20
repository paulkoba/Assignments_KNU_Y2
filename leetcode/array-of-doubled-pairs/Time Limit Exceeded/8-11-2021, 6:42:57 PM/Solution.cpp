// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        for(int i = 0; i < sz; ++i) {
            if(arr[i] == -10000000) continue;
            vector<int>::iterator iter;
            
            if(arr[i] >= 0) {
                iter = find(arr.begin(), arr.end(), arr[i] * 2);
            } else {
                if(arr[i] % 2 == -1) return false;
                iter = find(arr.begin(), arr.end(), arr[i] / 2);
            }
            
            if(iter == arr.end()) return false;
            *iter = -10000000;
            arr[i] = -10000000;
        }
        
        return true;
    }
};