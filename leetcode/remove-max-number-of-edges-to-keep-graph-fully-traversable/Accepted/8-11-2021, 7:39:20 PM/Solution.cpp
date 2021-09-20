// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        ++n;
        vector<int> parents(n);
        for(int i = 0; i < n; ++i) parents[i] = i;
        vector<int> size(n, 1);
        
        int output = 0;
        
        function<int (int)> findParent = [&](int el) -> int {
            if(parents[el] == el) return el;
            
            return parents[el] = findParent(parents[el]);
        };
        
        for(int i = 0; i < edges.size(); ++i) {
            if(edges[i][0] != 3) continue;
            
            int a = findParent(edges[i][1]);
            int b = findParent(edges[i][2]);
            
            if(a == b) {
                ++output;
                continue;
            }
            
            if(size[a] > size[b]) {
                parents[b] = a;
                size[a] += size[b];
            } else {
                parents[a] = b;
                size[b] += size[a];
            }
        }
        
        vector<int> cp = parents;
        vector<int> cpSz = size;
        
        for(int i = 0; i < edges.size(); ++i) {
            if(edges[i][0] != 1) continue;
            
            int a = findParent(edges[i][1]);
            int b = findParent(edges[i][2]);
            
            if(a == b) {
                ++output;
                continue;
            }
            
            if(size[a] > size[b]) {
                parents[b] = a;
                size[a] += size[b];
            } else {
                parents[a] = b;
                size[b] += size[a];
            }
        }

        int rootRed = findParent(1);
        
        for(int i = 1; i < n; ++i) {
            if(rootRed != findParent(i)) return -1;
        }
        
        
        findParent = [&](int el) -> int {
            if(cp[el] == el) return el;
            
            return cp[el] = findParent(cp[el]);
        };
        
        for(int i = 0; i < edges.size(); ++i) {
            if(edges[i][0] != 2) continue;
            
            int a = findParent(edges[i][1]);
            int b = findParent(edges[i][2]);
            
            if(a == b) {
                ++output;
                continue;
            }
            
            if(cpSz[a] > cpSz[b]) {
                cp[b] = a;
                cpSz[a] += cpSz[b];
            } else {
                cp[a] = b;
                cpSz[b] += cpSz[a];
            }
        }
        
        int rootGreen = findParent(1);
        
        for(int i = 1; i < n; ++i) {
            if(rootGreen != findParent(i)) return -1;
        }
        
        return output;
    }
};