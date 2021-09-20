// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings

class Solution {
public:
    int depth(const string& seq) {
        int curr = 0;
        int m = 0;
        
        for(char ch : seq) {
            if(ch == '(') {
                ++curr;
                m = max(m, curr);
            } else {
                --curr;
            }
        }
        
        return m;
    }
    
    vector<int> maxDepthAfterSplit(string seq) {
        int dep = depth(seq);
        int depthLower = dep / 2;
        
        vector<int> output(seq.size(), 0);
        
        int curr = 0;
        
        for(int i = 0; i < seq.size(); ++i){
            char ch = seq[i];
            
            if(ch == '(') {
                ++curr;
                if(curr > depthLower) {
                    output[i] = 1;
                } else {
                    output[i] = 0;
                }
            } else {
                if(curr > depthLower) {
                    output[i] = 1;
                } else {
                    output[i] = 0;
                }
                --curr;
            }
        }
        
        return output;
    }
};