// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> chars;
        for(char ch : S) ++chars[ch];
        
        unordered_map<char, int> charsCurrent;
        vector<int> output;
        int count = 0;
        
        for(char ch : S) {
            ++charsCurrent[ch];
            ++count;
            
            bool flag = true;
            
            for(const auto& iter : charsCurrent) {
                if(iter.second != chars[iter.first]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                charsCurrent = unordered_map<char, int>();
                output.push_back(count);
                count = 0;
            }
        }
            
        return output;
    }
};