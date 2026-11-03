class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int result = 0;
        for (const int& num : nums) {
            result += max - num;
        }
        return result;
    }
};