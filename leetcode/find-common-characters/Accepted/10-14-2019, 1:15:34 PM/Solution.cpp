// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int sz = A.size();
        vector<unordered_map<char, int>> data(sz);
        
        for(int i = 0; i < sz; ++i)
            for(char ch: A[i]) ++data[i][ch];
        
        vector<string> output;
        for(const auto& p : data[0]) {
            int minOcc = p.second;
            for(int i = 1; i < sz; ++i) minOcc = min(minOcc, data[i][p.first]);
            for(int i = 0; i < minOcc; ++i) output.push_back(string(1, p.first));
        }
        return output;
    }
};