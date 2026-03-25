class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pair;
        unordered_map<int, int> looking_for;
        for (int i = 0; i<nums.size(); i++) {
            int complement = target - nums[i];
            if(looking_for.find(complement) != looking_for.end()) {
                pair.push_back(i);
                pair.push_back(looking_for[complement]);
                break;
            }
            looking_for[nums[i]] = i;
        }
        return pair;
    }
};