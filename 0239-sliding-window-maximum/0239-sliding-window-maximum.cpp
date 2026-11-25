class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> maxes;

        vector<int> res;

        for(int i =0; i<k; ++i) {
            while(!maxes.empty() && maxes.front() < nums[i]) {
                maxes.pop_front();
            }
            maxes.emplace_front(nums[i]);
        }

        for(int i=k; i<n; ++i) {
            res.push_back(maxes.back());
            if(nums[i-k] == maxes.back()) {
                maxes.pop_back();
            }
            while(!maxes.empty() && maxes.front() < nums[i]) {
                maxes.pop_front();
            }
            maxes.emplace_front(nums[i]);
        }
        res.push_back(maxes.back());
        return res;
    }
};