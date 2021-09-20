// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string output(num1.size() + num2.size() + 1, 0);
        
        for(int i = 0; i < num1.size(); ++i) {
            for(int j = 0; j < num2.size(); ++j) {
                output[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
            
            int carryover = 0;
            for(int j = 0; j < output.size(); ++j) {
                output[j] += carryover;
                carryover = 0;
                if(output[j] > 9) {
                    int n = output[j];
                    output[j] = n % 10;
                    carryover = n / 10;
                }
            }
        }
        
        for(int i = 0; i < output.size(); ++i) output[i] += '0';
        
        while(output.size() > 0 && output.back() == '0') output.pop_back();
        if(output.size() == 0) output = "0";
        
        reverse(output.begin(), output.end());
        
        return output;
    }
};