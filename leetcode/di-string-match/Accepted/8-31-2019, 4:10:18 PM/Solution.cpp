// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.size();
        if(N == 0) return{};
        vector<int> output(N + 1);
        int low = 0;
        int high = N;
        for(int i = 0; i < N; i++) {
            if(S[i] == 'I') {
                output[i] = low++;
            } else {
                output[i] = high--;
            }
        }
        output[N] = low;
        return std::move(output);
    }
};