// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(const vector<int>& arr1, const vector<int>& arr2) {
        std::vector<int> output(arr1.size());
        std::vector<int> overflow;
        unordered_map<int, int> count;
        for(int i : arr2) {
            count[i] = 0;
        }
        
        for(int i : arr1) {
            if(count.find(i) != count.end()) {
                count[i]++;
            } else {
                overflow.push_back(i);
            }
        }
        
        int index = 0;
        for(int i : arr2) {
            int temp = count[i];
            for(int j = 0; j < temp; ++j) {
                output[index] = i;
                index++;
            }
        }
        
        sort(overflow.begin(), overflow.end());
        
        copy(overflow.begin(), overflow.end(), &(output[index]));
        
        return output;
    }
};