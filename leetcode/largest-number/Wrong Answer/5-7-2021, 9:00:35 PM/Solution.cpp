// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        
        for(int i : nums) str.push_back(to_string(i));
        
        sort(str.begin(), str.end(), [](const string& a, const string& b) {
            int n = min(a.size(), b.size());
            for(int i = 0; i < n; ++i) {
                if(a[i] < b[i]) return false;
                if(a[i] > b[i]) return true;
            }
            
            return a.size() > b.size() ? a[n] > b[0] : a[0] > b[n];
        });
        
        string output;
        
        for(const std::string& k : str) output += k;
        
        return output;
    }
};