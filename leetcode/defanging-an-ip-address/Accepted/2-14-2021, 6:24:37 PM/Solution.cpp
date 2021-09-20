// https://leetcode.com/problems/defanging-an-ip-address

class Solution {
public:
    string defangIPaddr(string address) {
        string output = "";
        for(char ch : address)  {
            if(ch == '.') {
                output.append("[.]");
            } else {
                output.append(1, ch);
            }
        }
        return output;
    }
};