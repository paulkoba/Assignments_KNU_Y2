// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        bool flag = true;
        for(int i : A) {
            if(i >= 0) {
                flag = false;
                break;
            }
        }
        if(flag) return *std::max_element(A.begin(), A.end());
        
        
        int currentBest = 0;
        
        int currentSumMax = 0;
        int currentSumMin = std::numeric_limits<int>::max() / 2;
        
        bool hintFullArray = true;
        
        int totalSum = accumulate(A.begin(), A.end(), 0);
        
        for(int i = 0; i < A.size(); ++i) {
            currentSumMax = max(A[i] + currentSumMax, A[i]);
            currentSumMin = min(A[i] + currentSumMin, A[i]);
            
            currentBest = max(currentBest, currentSumMax);
            currentBest = max(currentBest, totalSum - currentSumMin);
        }
        
        return currentBest;
    }
};