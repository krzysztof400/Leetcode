class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> DP(n, 1);
        
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&arr](const int& a, const int& b){
            return arr[a] < arr[b];
        });

        for(int i = 0; i<n; ++i) {
            int max_jump = 0;
            for(int j = 1; j<=d && j+ indices[i] < n; ++j) {
                if (arr[indices[i] + j] >= arr[indices[i]]) {
                    break;
                }
                max_jump = max(max_jump, DP[indices[i] + j]);
            }
            for(int j = 1; j<=d && indices[i] - j >= 0; ++j) {
                if (arr[indices[i] - j] >= arr[indices[i]]) {
                    break;
                }
                max_jump = max(max_jump, DP[indices[i] - j]);
            }
            // int max_jump = 0;
            // // printf("\n %d:      ", i);
            // for (int j : jumps) {
            //     // printf("%d, ", j);
            //     max_jump = max(max_jump, DP[j]);
            // }
            DP[indices[i]] = 1 + max_jump;
        }
        return *max_element(DP.begin(), DP.end());
    }
};