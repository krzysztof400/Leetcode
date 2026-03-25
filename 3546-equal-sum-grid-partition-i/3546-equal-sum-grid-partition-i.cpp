class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total_sum = 0;

        for(int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                total_sum += grid[i][j];
            }
        }

        if (total_sum % 2 == 1) {
            return false;
        }

        long long sum = 0;
        for(int i = 0; i < m; i++) {
            for(int n : grid[i]) {
                sum += n;
            }
            if (sum == total_sum - sum) {
                return true;
            }
        }

        sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j<m; j++) {
                sum += grid[j][i];
            }
            if(sum == total_sum - sum) {
                return true;
            }
        }
        return false;
    }
};