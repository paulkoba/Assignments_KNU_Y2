// https://leetcode.com/problems/course-schedule-ii

class Solution {
    void dfs(int numCourses, int i, vector<char>& visited, 
             vector<vector<int>>& req, vector<vector<int>>& courses, vector<int>& output) {
        if(visited[i]) return;
        visited[i] = true;
        output.push_back(i);
        for(int j : courses[i]) {
            bool flag = true;
            for(int k = 0; k < req[j].size(); ++k) {
                if(visited[req[j][k]] == false) {
                    flag = false;
                    break;
                }
            } 
            
            if(flag) {
                dfs(numCourses, j, visited, req, courses, output);
            }
        }
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses, vector<int>());
        vector<vector<int>> req(numCourses, vector<int>());
        vector<char> visited(numCourses, false);
        
        vector<int> output;
        
        for(const auto& i : prerequisites) {
            courses[i[0]].push_back(i[1]);
            req[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(req[i].size() == 0) {
                dfs(numCourses, i, visited, req, courses, output);
            }
        }
        
        for(char ch : visited) 
            if(ch != true) return {};
        
        reverse(output.begin(), output.end());
        return output;
    }
};