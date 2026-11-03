class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n, pivot);
        int left = 0;
        int right = n-1;
        for (int i = 0; i<n; ++i) {
            if(nums[i] < pivot) {
                res[left++] = nums[i];
            }
            if(nums[n-1-i] > pivot) {
                res[right--] = nums[n-1-i];
            }
        }
        return res;
    }
};