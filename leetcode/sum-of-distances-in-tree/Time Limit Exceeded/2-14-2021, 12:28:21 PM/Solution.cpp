// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
public:
    std::vector<int> sumOfDistancesInTree(int N, std::vector<std::vector<int>>& edges) {        
        std::vector<int> output;
        
        std::vector<std::vector<int>> nodes(N, std::vector<int>());
        
        for(const auto& edge : edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i < N; ++i) {
            std::vector<int> distances(N, 0);
            std::vector<bool> visited(N, 0);

            std::queue<int> bfs;
            bfs.push(i);   
            visited[i] = true;
            
            while(!bfs.empty()) {
                int node = bfs.front();
                bfs.pop();
                
                for(int i : nodes[node]) {
                    if(visited[i]) continue;
                    visited[i] = true;
                    distances[i] = distances[node] + 1;
                    bfs.push(i);
                }
            }
            
            output.push_back(std::accumulate(distances.begin(), distances.end(), 0));
        }
        
        return output;
    }
};