// https://leetcode.com/problems/numbers-with-same-consecutive-differences

class Solution {
    vector<int> generatePrefixes(int n, int k, const vector<int>& prevPref) {
        if(n == 0) return prevPref;
        
        vector<int> output;
        
        for(int a : prevPref) {
            int lastDigit = a % 10;
            
            if(lastDigit + k < 10) output.push_back(a * 10 + lastDigit + k);
            if(lastDigit - k >= 0) output.push_back(a * 10 + lastDigit - k);
        }
        
        return generatePrefixes(n - 1, k, output);
    }
public:
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto res = generatePrefixes(n - 1, k, digits);
        auto resSet = set(res.begin(), res.end());
        return {resSet.begin(), resSet.end()};
    }
};