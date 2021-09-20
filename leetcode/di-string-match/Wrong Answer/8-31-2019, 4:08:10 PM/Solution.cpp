// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.size();
        if(N == 0) return{};
        vector<int> output(N + 1);
        output[0] = 0;
        int low = 1;
        int high = N;
        for(int i = 0; i < N; i++) {
            if(S[i] == 'I') {
                output[i + 1] = high--;
            } else {
                output[i + 1] = low++;
            }
        }
        
        return std::move(output);
    }
};