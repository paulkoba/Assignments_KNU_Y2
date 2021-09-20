// https://leetcode.com/problems/distribute-repeating-integers

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> num;
        for(int i : nums)
            ++num[i];
        
        for(int j = quantity.size() - 1; j >= 0; --j) {
            int i = quantity[j];
            int smallest = 0;
            int tempSml = std::numeric_limits<int>::max();
            
            for(const auto& a : num) {
                if(a.second < tempSml && a.second >= i) {
                    smallest = a.first;
                    tempSml = a.second;
                }
            }
            
            if(num[smallest] < i) return false;
            num[smallest] -= i;
            
            if(num[smallest] == 0) num.erase(smallest);
        }
        
        return true;
    }
};