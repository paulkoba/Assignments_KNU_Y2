// https://leetcode.com/problems/previous-permutation-with-one-swap

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        for(int i = arr.size() - 2; i >= 0; --i) {
            int max = i + 1;
            
            for(int j = i + 1; j < arr.size(); ++j) {
                if(arr[j] > arr[max] && arr[j] < arr[i]) {
                    max = j;
                }
            }
            
            if(arr[max] < arr[i]) {
                swap(arr[max], arr[i]);
                
                return arr;
            }
        }
        
        return arr;
    }
};