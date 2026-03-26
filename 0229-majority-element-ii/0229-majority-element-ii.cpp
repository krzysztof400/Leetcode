class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> results;
        for (const int& num : nums) {
            count[num]++;
        }
        for ( const auto& [key, value] : count ) {
            if (value > floor(nums.size()/3)) {
                results.push_back(key);
            }
        }
        return results;
    }
};