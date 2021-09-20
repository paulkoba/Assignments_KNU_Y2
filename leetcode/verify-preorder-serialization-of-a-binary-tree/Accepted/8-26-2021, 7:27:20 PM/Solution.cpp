// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int balance = 1;
        preorder.push_back(',');
        
        for(int i = 1; i < preorder.size(); ++i) {
            if(preorder[i] == ',') --balance;
            if(balance < 0) return false;
            
            if(preorder[i] == ',' && preorder[i - 1] != '#') balance += 2;
        }
        
        return balance == 0;
    }
};