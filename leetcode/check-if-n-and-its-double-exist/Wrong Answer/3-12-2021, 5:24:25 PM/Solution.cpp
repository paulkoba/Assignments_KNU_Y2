// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> cont;
        for(int a : arr) {
            cont.insert(a);
            if(cont.find(a * 2) != cont.end() || (a % 2 == 0 && (cont.find(a / 2)) != cont.end())) return true;
        }
        return false;
    }
};