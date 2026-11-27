class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int& x : nums) {
            if(x <= 0) x = n+1;
        }

        for(int x : nums) {
            int v = abs(x);
            if(v <= n && nums[v-1] >0) {
                nums[v-1] = -nums[v-1];
            }
        }

        for(int i =0; i<n; ++i) {
            if(nums[i] > 0) {
                return i+1;
            }
        }

        return n+1;
    }
};