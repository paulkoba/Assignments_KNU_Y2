// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mm;
        for(auto elem : arr) ++mm[elem];
        
        set<pair<int, int>, greater<>> dd;
        
        for(const auto& p : mm) {
            dd.insert({p.second, p.first});
        }
        
        int currentCount = 0;
        int output = 0;
        
        for(const auto& p : dd) {
            currentCount += p.first;
            ++output;
            
            if(arr.size() <= currentCount * 2) break;
        }
        return output;
    }
};