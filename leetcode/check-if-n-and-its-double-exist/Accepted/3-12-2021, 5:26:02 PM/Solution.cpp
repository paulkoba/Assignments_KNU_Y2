// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> cont;
        for(int a : arr) {
            if(cont.find(a * 2) != cont.end() || ((2 + (a % 2) ) % 2 == 0 && (cont.find(a / 2)) != cont.end())) return true;
            cont.insert(a);
        }
        return false;
    }
};