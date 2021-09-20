// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size();
        int sz2 = num2.size();
        
        if(sz1 < sz2) {
            swap(num1, num2);
            swap(sz1, sz2);
        }
        
        for(int i = 0; i < sz2; ++i) {
            num1[sz1 - 1 - i] += num2[sz2 - 1 - i] - '0';
        }
        
        for(int i = sz1 - 1; i > 0; --i) {
            int num = (num1[i] - '0');
            if(num > 9) {
                num1[i - 1] += 1;
                num1[i] -= 10;
            }
        }
        
        if(num1[0] > '9') {
            string output = "1";
            output.append(num1);
            output[1] -= 10;
            
            return output;
        }
        
        return num1;
    }
};