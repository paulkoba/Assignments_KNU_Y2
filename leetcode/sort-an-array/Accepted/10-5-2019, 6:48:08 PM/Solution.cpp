// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    void heapify(vector<int>& nums, const int a, const int b) {
        int largest = b;
        const int left = b * 2 + 1;
        const int right = b * 2 + 2;
        
        if(left < a && nums[left] > nums[largest]) {
            largest = left;
        }
        
        if(right < a && nums[right] > nums[largest]) {
            largest = right;
        }
        
        if(largest != b) {
            swap(nums[b], nums[largest]);
            
            heapify(nums, a, largest);
        }
    }
    
    vector<int>& sortArray(vector<int>& nums) {
        const int size = nums.size();
        for(int i = size / 2 - 1; i >= 0; --i)
            heapify(nums, size, i);
        
        for(int i = size - 1; i >= 0; --i) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        
        return nums;
    }
};