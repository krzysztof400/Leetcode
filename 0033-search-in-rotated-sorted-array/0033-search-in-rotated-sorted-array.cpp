class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int idx = -1;
        while(right >= left) {
            int mid = (left+right) / 2;
            // printf("right: %d, left: %d, mid: %d \n", right, left, mid);
            // found
            if(nums[mid] == target) {
                idx = mid;
                break;
            }
            else if (nums[mid] > target) {
                // case where we chose diffrent half anyway
                if (nums[right] >= target && nums[mid] > nums[right]) {
                    left = mid+1;
                }
                // normal bs
                else {
                    right = mid-1;
                }
            }
            else if (nums[mid] < target) {
                // case where we chose diffrent half anyway
                if (target >= nums[left] && nums[left] > nums[mid]) {
                    right = mid-1;
                }
                // normal bs
                else {
                    left = mid+1;
                }
            }
        }
        return idx;
    }
};