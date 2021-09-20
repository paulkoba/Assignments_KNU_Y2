// https://leetcode.com/problems/complex-number-multiplication

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int i1 = 0;
        while(num1[i1] !='+') ++i1;
        string real1 = num1.substr(0, i1);
        string im1 = num1.substr(i1 + 1);
        im1.pop_back();
        int i2 = 0;
        while(num2[i2] != '+') ++i2;
        string real2 = num2.substr(0, i2);
        string im2 = num2.substr(i2 + 1);
        im2.pop_back();


        return to_string(stoi(real1) * stoi(real2) - stoi(im1) * stoi(im2)) + "+" 
            + to_string(stoi(real1) * stoi(im2) + stoi(real2) * stoi(im1)) + "i";
    }
};