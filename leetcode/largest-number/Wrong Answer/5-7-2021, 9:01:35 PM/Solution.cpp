// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        
        for(int i : nums) str.push_back(to_string(i));
        
        sort(str.begin(), str.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        string output;
        
        for(const std::string& k : str) output += k;
        
        return output;
    }
};