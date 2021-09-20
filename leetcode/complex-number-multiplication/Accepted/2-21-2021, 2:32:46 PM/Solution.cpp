// https://leetcode.com/problems/complex-number-multiplication

class Solution {
    pair<int, int> parse(const string& s) {
        int a = 0, b = 0;
        int idx = 0;
        bool flag = false;
        if(s[0] == '-') {
            flag = true;
            ++idx;
        }
        
        while(s[idx] >= '0' && s[idx] <= '9') {
            a = a * 10 + s[idx] - '0';
            ++idx;
        }
        
        if(flag) a = -a;
        flag = false;
        
        ++idx;
        if(s[idx] == '-') {
            flag = true;
            ++idx;
        }
        
        while(s[idx] >= '0' && s[idx] <= '9') {
            b = b * 10 + s[idx] - '0';
            ++idx;
        }
        if(flag) b = -b;

        return {a, b};
    }
    
public:
    string complexNumberMultiply(string a, string b) {
        string output;
        auto i = parse(a);
        auto j = parse(b);
        output.append(to_string(i.first * j.first - i.second * j.second));
        output.append("+");
        output.append(to_string(i.first * j.second + i.second * j.first));
        output.append("i");
        
        return output;
    }
};