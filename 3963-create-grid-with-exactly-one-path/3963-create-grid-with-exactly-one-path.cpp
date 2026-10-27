class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result;        
        result.push_back(std::string(n, '.'));
        for(int i = 1; i<m; i++) {
            result.push_back(string(n-1, '#') + '.');
        }
        return result;
    }
};