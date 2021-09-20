// https://leetcode.com/problems/k-th-smallest-prime-fraction

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        size_t sz = A.size();
        vector<pair<double, pair<int, int>>> fractions(sz * (sz - 1) / 2);
        size_t idx = 0;
        for(int i = 0; i < sz; ++i) {
            for(int j = i + 1; j < sz; ++j) {
                if(A[i] < A[j]) {
                    fractions[idx++] = make_pair((double)A[i] / (double)A[j], make_pair(A[i], A[j]));
                } else {
                    fractions[idx++] = make_pair((double)A[j] / (double)A[i], make_pair(A[j], A[i]));
                }
            }
        }
        
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>,
            greater<pair<double, pair<int, int>>>> data(fractions.begin(), fractions.end());
        
        for(int i = 1; i < K; ++i) data.pop();
        
        return {data.top().second.first, data.top().second.second};
    }
};