// https://leetcode.com/problems/course-schedule

class Solution {
    void dfs(int numCourses, int i, vector<char>& visited, 
             vector<vector<int>>& req, vector<vector<int>>& courses) {
        if(visited[i]) return;
        visited[i] = true;
        for(int j : courses[i]) {
            bool flag = true;
            for(int k = 0; k < req[j].size(); ++k) {
                if(visited[req[j][k]] == false) {
                    flag = false;
                    break;
                }
            } 
            
            if(flag) {
                dfs(numCourses, j, visited, req, courses);
            }
        }
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses, vector<int>());
        vector<vector<int>> req(numCourses, vector<int>());
        vector<char> visited(numCourses, false);
        
        for(const auto& i : prerequisites) {
            courses[i[0]].push_back(i[1]);
            req[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(req[i].size() == 0) {
                dfs(numCourses, i, visited, req, courses);
            }
        }
        
        for(char ch : visited) 
            if(ch != true) return false;
        
        return true;
    }
};