// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> p(mat.size());
        
        for(int i = 0; i < mat.size(); ++i) {
            for(int ch : mat[i]) {
                if(ch == 0) break;
                ++p[i];
            }
        }
        
        vector<pair<int, int>> num(mat.size());
        
        for(int i = 0; i < mat.size(); ++i) {
            num[i] = make_pair(-p[i], -i);
        }
        
        make_heap(num.begin(), num.end());
        
        vector<int> output;
        for(int i = 0; i < k; ++i) {
            pop_heap(num.begin(), num.end());
            output.push_back(-num.back().second);
            num.pop_back();
        }
        
        return output;
    }
};