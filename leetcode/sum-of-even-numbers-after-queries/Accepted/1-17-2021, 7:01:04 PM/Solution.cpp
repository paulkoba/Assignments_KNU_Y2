// https://leetcode.com/problems/sum-of-even-numbers-after-queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int count = 0;
        
        vector<int> output(queries.size());
        
        for(int i : A) {
            count += i % 2 == 0 ? i : 0;
        }
        
        for(int i = 0; i < queries.size(); ++i) {
            int index = queries[i][1];
            
            if(A[index] % 2 == 0) count -= A[index];
            
            A[index] += queries[i][0];
            
            if(A[index] % 2 == 0) count += A[index];
            
            output[i] = count;
        }
        
        return output;
    }
};