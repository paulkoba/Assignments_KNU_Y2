// https://leetcode.com/problems/k-th-smallest-prime-fraction

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        size_t sz = A.size();
        priority_queue<pair<double, pair<int, int>>> data;
        for(int i = 0; i < sz; ++i) {
            for(int j = i + 1; j < sz; ++j) {
                if(data.size() < K) {
                    data.push(make_pair((double)A[i] / (double)A[j], make_pair(A[i], A[j])));
                } else {
                    if((double)A[i] / (double)A[j] < data.top().first) {
                        data.pop();
                        data.push(make_pair((double)A[i] / (double)A[j], make_pair(A[i], A[j])));
                    }   
                }
            }
        }

        return {data.top().second.first, data.top().second.second};
    }
};