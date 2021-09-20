// https://leetcode.com/problems/powerful-integers

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int k = log(bound) / log(x) + 1;
        if(x == 1) k = 1;
        set<int> output;
        
        int corner_case = (y == 1);
        
        for(int i = 0; i < k; ++i) {
            int temp_pow = pow(x, i);
            
            if(corner_case) {
                if((temp_pow + 1) <= bound) output.insert(temp_pow + 1);
                continue;
            }
            
            for(int j = 0; true; ++j) {
                int result = pow(y, j) + temp_pow;
                if(result <= bound) {
                    output.insert(result);
                } else {
                    break;
                }
            }
        }
        
        return vector<int>(output.begin(), output.end());
    }
};