// https://leetcode.com/problems/fizz-buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> output(n);
        
        for(int i = 1; i <= n; ++i) {
            if(i % 3 == 0 && i % 5 == 0) {
                output[i - 1] = "FizzBuzz";
                continue;
            }
            
            if(i % 3 == 0) {
                output[i - 1] = "Fizz";
                continue;
            }
            
            if(i % 5 == 0) {
                output[i - 1] = "Buzz";
                continue;
            }
            
            output[i - 1] = to_string(i);
        }
        
        return output;
    }
};