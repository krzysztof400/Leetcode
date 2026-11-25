class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> maxes;
        vector<int> res;

        for(int i=0; i<n; ++i) {
            if(i >= k && nums[i-k] == maxes.back()) {
                maxes.pop_back();
            }
            while(!maxes.empty() && maxes.front() < nums[i]) {
                maxes.pop_front();
            }
            maxes.emplace_front(nums[i]);
            if (i >= k-1) res.push_back(maxes.back());
        }
        return res;
    }
};