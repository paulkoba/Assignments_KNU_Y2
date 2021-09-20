// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        string output = " ";
        
        for(char ch : s) {
            if(output.back() == ch) {
                output.pop_back();
            } else {
                output.push_back(ch);
            }
        }
        
        return output.substr(1, output.size() - 1);
    }
};