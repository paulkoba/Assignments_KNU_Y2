// https://leetcode.com/problems/count-of-smaller-numbers-after-self

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

template <typename T, typename U>
using tree = __gnu_pbds::tree<T, U, std::less<>, __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<int> output(sz);
        tree<pair<int, int>, char> sorted;
        
        for(int i = sz - 1; i >= 0; --i) {    
            sorted.insert({{nums[i], i}, 0});
            output[i] = sorted.order_of_key({nums[i], i});
        }
        return output;
    }
};