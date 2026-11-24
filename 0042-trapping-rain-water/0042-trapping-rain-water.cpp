class Solution {
public:
    int trap(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        // for(int i = 1; i<n; ++i) {
        //     int maxNxt = nums[i];
        //     int maxPrev = nums[i];
        //     for (int nxt = i; nxt<n; ++nxt) {
        //         maxNxt = max(maxNxt, nums[nxt]);
        //     }
        //     for (int prev = i; prev>=0; --prev) {
        //         maxPrev = max(maxPrev, nums[prev]);
        //     }
        //     int mini = min(maxPrev, maxNxt);
        //     sum += mini - nums[i];

        //     // cout << "index: " << i << " amm of water: " << mini - nums[i] << " min: " << mini << endl;
        // }

        // int prev_idx = 0;
        // int next_idx = 0;
        // int mini;
        // for (int i =0; i<n-1; ++i) {
        //     if (i<next_idx) {
        //         sum += mini- nums[i];
        //     }
        //     else {
        //         prev_idx = next_idx;
        //         for(int j = prev_idx+1; nums[next_idx] < nums[prev_idx]; ++j) {
        //             if (nums[j] >= nums[next_idx]) next_idx = j;
        //         }
        //         mini = min(nums[prev_idx], nums[next_idx]);
        //     }
        // }

        int left = 0;
        int right = n-1;
        int maxLeft = 0;
        int maxRight = 0;
        while(left<right) {
            if(nums[left] <= nums[right]){
                maxLeft = max(nums[left], maxLeft);
                sum += maxLeft - nums[left++];
            }
            else {
                maxRight = max(nums[right], maxRight);
                sum += maxRight - nums[right--];
            }
        }

        return sum;
    }
};