class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        int rem = total_sum % p;
        if (rem == 0) {
            return 0;
        }

        unordered_map<int, int> last_seen;
        last_seen[0] = -1;

        long long current_sum = 0;
        int min_len = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            int current_mod = current_sum % p;

            int target = (current_mod - rem + p) % p;

            if (last_seen.count(target)) {
                min_len = min(min_len, i - last_seen[target]);
            }

            last_seen[current_mod] = i;
        }

        if (min_len == nums.size()) {
            return -1;
        } else {
            return min_len;
        }
    }
};