class Solution {
private:
    const long long MOD = 1000000007;
    const long long INV_2 = 500000004;

public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> numbers_in_line;
        for (const auto& p : points) {
            numbers_in_line[p[1]]++;
        }

        long long sum_of_c2 = 0; // S = sum(C_k)
        long long sum_of_c2_squared = 0; // sum(C_k^2)

        for (const auto& entry : numbers_in_line) {
            long long N = entry.second;
            
            if (N < 2) continue;

            long long C_k = (N * (N - 1)) / 2;
            
            C_k %= MOD;

            sum_of_c2 = (sum_of_c2 + C_k) % MOD;

            long long C_k_squared = (C_k * C_k) % MOD;
            sum_of_c2_squared = (sum_of_c2_squared + C_k_squared) % MOD;
        }

        long long S_squared = (sum_of_c2 * sum_of_c2) % MOD;

        long long difference = (S_squared - sum_of_c2_squared + MOD) % MOD;
        
        long long total_num_of_trapezoids = (difference * INV_2) % MOD;

        return (int)total_num_of_trapezoids;
    }
};