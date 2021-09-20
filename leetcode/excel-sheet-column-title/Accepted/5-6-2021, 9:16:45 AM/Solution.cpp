// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string output;
        while(columnNumber) {
            --columnNumber;
            output.append(1, 'A' + (columnNumber % 26));
            columnNumber /= 26;
        }
        reverse(output.begin(), output.end());
        return output;
    }
};