// https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> output;
        
        int minDifference = std::numeric_limits<int>::max();
        for(int i = 1; i < arr.size(); ++i) {
            if(minDifference > arr[i] - arr[i - 1])
                minDifference = arr[i] - arr[i - 1];
        }
        
        for(int i = 1; i < arr.size(); ++i) {
            if(minDifference == arr[i] - arr[i - 1])
                output.push_back({arr[i - 1], arr[i]});
        }        
        
        return output;
    }
};