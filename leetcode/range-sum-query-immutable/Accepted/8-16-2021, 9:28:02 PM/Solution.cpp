// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    unordered_map<int, int> mm;
    
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            mm[i] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return mm[right];
        
        return mm[right] - mm[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */