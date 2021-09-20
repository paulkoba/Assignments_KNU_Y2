// https://leetcode.com/problems/fraction-addition-and-subtraction

pair<int, int> addition(int num1, int den1, int num2, int den2) {
    int64_t num = num1 * den2 + num2 * den1;
    uint64_t den = den1 * den2;
    uint64_t gcd_tmp = gcd(abs(num), den);
    
    return make_pair<int, int>(num / gcd_tmp, den / gcd_tmp);
}

uint64_t gcd(uint64_t a, uint64_t b) {
    return b == 0 ? gcd(b, a % b) : a;
}

class Solution {
public:
    string fractionAddition(const string& expression) {
        int numerator = 0;
        int denominator = 0;
        bool sign = true;
        bool part = true;
        int currentNumerator = 0;
        int currentDenominator = 0;
        for(char ch : expression) {
            if(ch >= '0' && ch <= '9') {
                if(part) {
                    numerator = numerator * 10 + ch - '0';
                } else {
                    denominator = denominator * 10 + ch - '0';
                }
            } else if(ch == '/') {
                part = false;
            } else {
                if(currentNumerator == 0) {
                    currentNumerator = sign ? numerator : -numerator;
                    currentDenominator = denominator;
                } else if(numerator != 0) {
                    auto p = addition(sign ? numerator : -numerator, denominator,
                        currentNumerator, currentDenominator);
                    currentNumerator = p.first;
                    currentDenominator = p.second;
                }

                numerator = 0;
                denominator = 0;
                part = true;
                sign = (ch == '+');
            }
        }
        
        if(currentNumerator == 0) {
            currentNumerator = sign ? numerator : -numerator;
            currentDenominator = denominator;
        } else if(numerator != 0) {
            auto p = addition(sign ? numerator : -numerator, denominator,
                currentNumerator, currentDenominator);
            currentNumerator = p.first;
            currentDenominator = p.second;
        }
        
        return to_string(currentNumerator).append("/").append(to_string(currentDenominator));
    }
};