// https://leetcode.com/problems/mean-of-array-after-removing-some-elements

class Solution {
public:
    double trimMean(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        
        size_t frac = arr.size() / 20;
        double sum = 0;
        for(size_t i = frac; i < frac * 19; ++i) {
            sum += arr[i];
        }
        
        return sum / (frac * 18);
    }
};