// https://leetcode.com/problems/generate-parentheses

class Solution {
private:
    vector<string> generateParenthesisInner(int n, int balance) {
        if(balance > n) return {};
        if(n == 0) return {""};

        vector<string> output;
        
        auto opening = generateParenthesisInner(n - 1, balance + 1);
        for(const string& val : opening) output.push_back("(" + val);
        
        if(balance > 0) {
            auto closing = generateParenthesisInner(n - 1, balance - 1);
            for(const string& val : closing) output.push_back(")" + val);
        }
        
        return output;
    }
public:
    vector<string> generateParenthesis(int n) {
        return generateParenthesisInner(n * 2, 0);
    }
};