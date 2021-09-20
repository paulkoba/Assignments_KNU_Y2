// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int currentBest = std::numeric_limits<int>::min();
        
        int currentSumMax = std::numeric_limits<int>::min() / 2;
        int currentSumMin = std::numeric_limits<int>::max() / 2;
        
        bool hintFullArray = true;
        
        int totalSum = accumulate(A.begin(), A.end(), 0);
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] > 0) hintFullArray = false;
            
            currentSumMax = max(A[i] + currentSumMax, A[i]);
            currentSumMin = min(A[i] + currentSumMin, A[i]);
            
            currentBest = max(currentBest, currentSumMax);
            
            if(!hintFullArray || i != A.size() - 1)
                currentBest = max(currentBest, totalSum - currentSumMin);
        }
        
        return currentBest;
    }
};