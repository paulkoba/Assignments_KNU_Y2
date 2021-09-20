// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> output(nums1.size());
        int i = 0, j = 0, k = 0;
        
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                output[k++] = nums1[i++];
            } else {
                output[k++] = nums2[j++];
            }
        }
        
        while(i < m) output[k++] = nums1[i++];
        while(j < n) output[k++] = nums2[j++];
        
        nums1 = output;
    }
};