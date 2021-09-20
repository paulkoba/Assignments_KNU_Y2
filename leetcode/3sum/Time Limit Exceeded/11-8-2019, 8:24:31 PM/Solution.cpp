// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> output;
        size_t sz = nums.size();
        for(auto a = nums.begin(); a != nums.end(); ++a) {
            for(auto b = a + 1; b != nums.end(); ++b) {
                int sum2 = *a + *b;
                
                if(binary_search(b + 1, nums.end(), -sum2))
                    output.insert({*a, *b, -sum2});
            }
        }
        
        return vector(output.begin(), output.end());
    }
};