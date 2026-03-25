class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<unsigned long long> rows_value (m);
        vector<unsigned long long> columns_value (n);

        for(int i = 0; i < m; i++) {
            if (i != 0) {
                rows_value[i] = rows_value[i-1];
            }
            for(int n : grid[i]) {
                rows_value[i] += n;
            }
        }

        for(int i = 0; i < n; i++) {
            if (i != 0) {
                columns_value[i] = columns_value[i-1];
            }
            for(int j = 0; j<m; j++) {
                columns_value[i] += grid[j][i];
            }
        }
    
        for(unsigned long long sum : rows_value) {
            if (sum == rows_value[m-1] - sum) {
                return true;
            }
        }
        for(unsigned long long sum : columns_value) {
            if (sum == columns_value[n-1] - sum) {
                return true;
            }
        }
        return false;
    }
};