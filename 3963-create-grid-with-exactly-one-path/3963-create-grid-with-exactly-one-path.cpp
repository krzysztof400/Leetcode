class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;        
        result.push_back(std::string(n, '.'));
        string other_row = string(n-1, '#') + '.';
        for(int i = 1; i<m; i++) {
            result.push_back(other_row);
        }
        return result;
    }
};