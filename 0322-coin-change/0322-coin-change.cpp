class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount+1, amount+1);

        DP[0] = 0;

        for(int i = 1; i<amount+1; ++i) {
            for(const int& coin : coins) {
                if (i-coin >= 0) {
                    DP[i] = min(DP[i-coin] + 1, DP[i]);
                }
            }
        }
        if (DP[amount] == amount+1) {
            return -1;
        }
        return DP[amount];
    }
};