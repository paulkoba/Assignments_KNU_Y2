// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(const vector<int>& nums) {
        vector<vector<int>> output;
        size_t sz = nums.size(), k = 0;
        if(sz < 3) return {};
        
        //Remove elements that occur multiple times.
        unordered_map<int, int> temp;
        for(int i : nums) ++temp[i];
        vector<int> new_nums(temp.size());
        for(const auto& t : temp) {
            new_nums[k++] = t.first;
            if(t.second > 1) {
                if(find(nums.begin(), nums.end(), -t.first * 2) != nums.end()) {
                    if(t.first == 0 && t.second < 3) continue;
                    output.push_back({t.first, t.first, -t.first * 2});
                } 
            }
        }
        
        sort(new_nums.begin(), new_nums.end());
        
        for(auto a = new_nums.begin(); a != new_nums.end(); ++a) {
            for(auto b = a + 1; b != new_nums.end(); ++b) {
                int sum2 = *a + *b;
                
                if(sum2 > 0) break;
                
                if(binary_search(b + 1, new_nums.end(), -sum2))
                    output.push_back({*a, *b, -sum2});
            }
        }
        
        return output;
    }
};