// https://leetcode.com/problems/string-without-aaa-or-bbb

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string output(A + B, ' ');
        
        size_t index = 0;
        
        if(B == 0) return string(A, 'a');
        if(A == 0) return string(B, 'b');
        
        while(A > B && B >= 1) {
            output[index++] = 'a';
            output[index++] = 'a';
            output[index++] = 'b';
            A -= 2;
            B -= 1;
        }
        
        while(B > A && A >= 1) {
            output[index++] = 'b';
            output[index++] = 'b';
            output[index++] = 'a';
            A -= 1;
            B -= 2;
        }
        
        while(A != 0 && B != 0) {
            output[index++] = 'a';
            output[index++] = 'b';
            A--;
            B--;
        }
        
        while(A-- != 0) output[index++] = 'a';
        while(B-- != 0) output[index++] = 'b';
        
        return move(output);
    }
};