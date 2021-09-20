// https://leetcode.com/problems/heaters

static int closest(const vector<int>& arr, int target) {
    if(target <= arr[0]) return arr[0];
    if(target >= arr[arr.size() - 1]) return arr[arr.size() - 1];
    
    auto out = upper_bound(arr.begin(), arr.end(), target);
    
    return (*out - target > target - (*(out - 1))) ? *(out-1) : *out;
}

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int radius = 0;
        
        for(int i : houses) {
            radius = max(radius, abs(i - closest(heaters, i)));
        }
        
        return radius;
    }
};