class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        tails.reserve(sqrt(nums.size()));

        for(int i = 0; i<nums.size(); ++i) {
            int siz = tails.size();
            for (int j = 0; j <= siz; ++j) {
                if (j == tails.size()) tails.emplace_back(nums[i]);
                else if (nums[i] < tails[j]) {
                    tails[j] = nums[i];
                    break;
                }
                else if (nums[i] == tails[j]) break;
            }
        }

        return tails.size();
    }
};