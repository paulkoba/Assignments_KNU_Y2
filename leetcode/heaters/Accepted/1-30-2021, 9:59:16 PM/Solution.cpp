// https://leetcode.com/problems/heaters

static int closest(const vector<int>& arr, int target) {
    if(target <= arr[0]) return arr[0];
    if(target >= arr[arr.size() - 1]) return arr[arr.size() - 1];
    
    int i = 0, j = arr.size(), mid = 0;
    
    while(i < j) {
        mid = (i + j) / 2;
        
        if(arr[mid] == target) return arr[mid];
        
        if(target < arr[mid]) {
            if(target > arr[mid - 1] && mid > 0)
                return target - arr[mid - 1] >= arr[mid] - target ? arr[mid] : arr[mid - 1];
            
            j = mid;
        } else {
            if (target < arr[mid + 1] && mid < arr.size() - 1)
                return target - arr[mid] >= arr[mid + 1] - target ? arr[mid + 1] : arr[mid];
            
            i = mid + 1;
        }
        
    }
    
    return arr[mid];
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