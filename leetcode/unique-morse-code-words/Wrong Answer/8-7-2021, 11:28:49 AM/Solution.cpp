// https://leetcode.com/problems/unique-morse-code-words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mapping = {".-","-...","-.-.","-..",".","..-.","--.",
                              "....","..",".---","-.-",".-..","--","-.",
                              "---",".--.","--.-",".-.","...","-","..-",
                              "...-",".--","-..-","-.--","--.."};
        
        set<string> transformations;
        
        for(const string& str : words) {
            string transformed;
            for(char ch : str) {
                transformed.append(mapping[ch - 'a'], 1);
            }
            transformations.insert(transformed);
        }
        
        return transformations.size();
    }
};