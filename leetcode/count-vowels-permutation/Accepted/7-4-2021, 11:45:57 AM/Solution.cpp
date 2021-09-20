// https://leetcode.com/problems/count-vowels-permutation

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

class Solution {
public:
    unordered_map<pair<int, char>, int64_t, pair_hash> memo;
    
    int64_t countVowelPermutation(int n, char prev) {
        if(n == 0) return 1;
        if(memo.find({n, prev}) != memo.end()) return memo[{n, prev}];
        
        switch(prev) {
            case ' ':
                return memo[{n, prev}] = (countVowelPermutation(n - 1, 'a') + 
                    countVowelPermutation(n - 1, 'e') +
                    countVowelPermutation(n - 1, 'i') + 
                    countVowelPermutation(n - 1, 'o') +
                    countVowelPermutation(n - 1, 'u')) % (1000000007);
            case 'a':
                return memo[{n, prev}] = countVowelPermutation(n - 1, 'e');               
            case 'e':
                return memo[{n, prev}] = (countVowelPermutation(n - 1, 'a') + 
                    countVowelPermutation(n - 1, 'i')) % (1000000007);                
            case 'i':
                return memo[{n, prev}] = (countVowelPermutation(n - 1, 'a') + 
                    countVowelPermutation(n - 1, 'e') +
                    countVowelPermutation(n - 1, 'o') +
                    countVowelPermutation(n - 1, 'u')) % (1000000007);
            case 'o':
                return memo[{n, prev}] = (countVowelPermutation(n - 1, 'i') + 
                    countVowelPermutation(n - 1, 'u')) % (1000000007);
            case 'u':
                return memo[{n, prev}] = countVowelPermutation(n - 1, 'a');
            default:
                return numeric_limits<int>::min();
        }
    }
    
    int countVowelPermutation(int n) {
        return countVowelPermutation(n, ' ');
    }
};