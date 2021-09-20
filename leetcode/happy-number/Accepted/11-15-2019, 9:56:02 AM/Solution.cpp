// https://leetcode.com/problems/happy-number

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> temp;
        
        while(n != 1) {
            int k = 0;
            
            while(n != 0) {
                k += pow(n % 10, 2);
                n /= 10;
            }
            
            if(temp.find(k) != temp.end()) {
                return false;
            }
            temp.insert(k);
            
            n = k;
        }
        
        return true;
    }
};