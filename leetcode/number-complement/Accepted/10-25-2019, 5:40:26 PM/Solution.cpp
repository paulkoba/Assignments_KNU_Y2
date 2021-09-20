// https://leetcode.com/problems/number-complement

int64_t findCpl(int64_t num) {
    int count = 0;
    int64_t temp = num;
    while(temp) {
        temp = temp >> 1;
        ++count;
    }
    return ((int64_t)pow(2, count) - 1) ^ num;
}

class Solution {    
public:
    int findComplement(int num) {
        return findCpl((uint32_t)num);
    }
};