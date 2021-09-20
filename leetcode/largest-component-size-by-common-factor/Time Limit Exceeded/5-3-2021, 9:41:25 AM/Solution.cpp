// https://leetcode.com/problems/largest-component-size-by-common-factor

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
        int n = A.size();
        parents.clear();
        parents.reserve(n);
        sz.clear();
        sz.reserve(n);
        
        for(int i = 0; i < n; ++i) {
            parents[i] = i;
            sz[i] = 1;
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                int g = __gcd(A[i], A[j]);
                if(g != 1) {
                    union_sets(i, j);
                }
            }
        }
        
        int m = 0;
        
        for(int i = 0; i < n; ++i) m = max(sz[i], m);
        
        return m;
    }
};