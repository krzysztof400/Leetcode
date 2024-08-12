class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        result.push_back(nums.at(0));
        for(int i = 1; i<nums.size(); i++){
            result.push_back(result.at(i-1)+nums.at(i));
        }
        return result;
    }
};