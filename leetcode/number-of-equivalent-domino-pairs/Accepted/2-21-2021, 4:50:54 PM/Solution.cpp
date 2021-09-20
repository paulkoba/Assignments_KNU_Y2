// https://leetcode.com/problems/number-of-equivalent-domino-pairs

struct hasher {
    size_t operator()(const vector<int>& a) const {
        return hash<int>{}(a[0]) ^ hash<int>{}(a[1]);
    }
};

class Solution {  
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        for(int i = 0; i < dominoes.size(); ++i) 
            if(dominoes[i][0] < dominoes[i][1]) swap(dominoes[i][0], dominoes[i][1]);
        
        unordered_map<vector<int>, int, hasher> s;
        
        int output = 0;
        for(const auto& dom : dominoes) {
            output += s[dom];
            ++s[dom];
        }
        
        return output;
    }
};