// https://leetcode.com/problems/largest-component-size-by-common-factor

bool isPrime[100000] = {};
bool isInitialized = false;
vector<pair<int, int>> primes;

class Solution {
public:
    vector<int> parents;
    vector<int> sz;
    
    int find_set(int v) {
        if(v == parents[v]) return v;
        
        return parents[v] = find_set(parents[v]);
    }
    
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        
        if(a != b) {
            if(sz[a] < sz[b]) swap(a, b);
            
            parents[b] = a;
            sz[a] += sz[b];
        }
    }
    
    int largestComponentSize(vector<int>& A) {
        if(A.size() == 1) return 1;
        
        if(!isInitialized) {
            isPrime[0] = 1;
            isPrime[1] = 1;
            isPrime[2] = 0;

            for(int i = 2; i < 100000; ++i) {
                if(isPrime[i]) continue;
                for(int j = i * 2; j < 100000; j += i) isPrime[j] = 1;
            }
            
            for(int i = 0; i < 100000; ++i) if(!isPrime[i]) primes.push_back({i, -1});
            
            isInitialized = true;
        }
                
        int n = A.size();
        parents.clear();
        parents.reserve(n);
        sz.clear();
        sz.reserve(n);
                
        for(int i = 0; i < n; ++i) {
            parents[i] = i;
            sz[i] = 1;
        }
        
        for(auto& it : primes) it.second = -1;
        
        for(int i = 0; i < n; ++i) {
            while(!(A[i] & 0b11)) A[i] >>= 1;
            for(auto& it : primes) {
                if(it.first > A[i]) break;
                if(A[i] % it.first == 0) {
                    if(it.second == -1) {
                        it.second = i;
                    } else {
                        union_sets(i, it.second);
                    }
                    A[i] /= it.first;
                }
            }
        }
        
        int m = 0;
        
        for(int i = 0; i < n; ++i) m = max(sz[i], m);
        
        return m;
    }
};