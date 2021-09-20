// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, greater<pair<int, size_t>>> numbers;
        vector<int> positions(m);
        size_t last_row = 0;
        
        for(size_t i = 0; i < m; ++i)
            numbers.push(make_pair(i + 1, i));
        
        for(size_t i = 1; i < k; ++i) {
            size_t last = numbers.top().second;
            numbers.pop();
            if(positions[last] < n - 1)
                numbers.push(make_pair((last + 1) * (++positions[last] + 1), last));
        }
        
        size_t last = numbers.top().second;
        return (last + 1) * (positions[last] + 1);
    }
};