class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end(), std::greater<int>());
        long long result = 0;

        for (int i = 0; i < k; i++) {
            result += std::max(0, happiness[i] - i);
        }

        return result;
    }
};
