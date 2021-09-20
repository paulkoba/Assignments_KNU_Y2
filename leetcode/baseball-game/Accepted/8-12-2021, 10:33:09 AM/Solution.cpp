// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        
        for(const string& str : ops) {
            int sz = st.size();
            
            if(str == "+") {
                st.push_back(st[sz - 1] + st[sz - 2]);
                continue;
            }
            
            if(str == "D") {
                st.push_back(2 * st[sz - 1]);
                continue;
            }
            
            if(str == "C") {
                st.pop_back();
                continue;
            }
            
            st.push_back(stoi(str));
        }
        
        return accumulate(st.begin(), st.end(), 0);
    }
};