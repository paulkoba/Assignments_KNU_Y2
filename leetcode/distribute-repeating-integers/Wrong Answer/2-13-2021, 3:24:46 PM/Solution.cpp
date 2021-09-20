// https://leetcode.com/problems/distribute-repeating-integers

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> num;
        for(int i : nums)
            ++num[i];
        
        for(int j = quantity.size() - 1; j >= 0; --j) {
            int i = quantity[j];
            int smallest = num.begin()->first;
            
            for(auto a : num) {
                if(a.second < num[smallest] && a.second >= i)
                    smallest = a.first;
            }
            
            if(num[smallest] < i) return false;
            num[smallest] -= i;
            
            if(num[smallest] == 0) num.erase(smallest);
        }
        
        return true;
    }
};