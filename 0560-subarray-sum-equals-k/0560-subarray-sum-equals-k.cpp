class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int res = 0;
        int prefix = 0;

        unordered_map<int, int> app;
        app[0] = 1;

        // num of prefixSum[i] - prefixSum[j] == k
        for(int i = 0; i<n; ++i) {
            prefix = prefix + nums[i];
            if(app.find(prefix - k) != app.end()) res += app[prefix - k];
            app[prefix]++;
        }

        return res;
    }
};