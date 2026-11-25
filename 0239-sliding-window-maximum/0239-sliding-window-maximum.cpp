class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        list<pair<int, int>> maxes;
        unordered_map<int, list<pair<int, int>>::iterator> ite;
        ite.reserve(k);

        vector<int> res;

        for(int i =0; i<k; ++i) {
            while(!maxes.empty() && maxes.front().first < nums[i]) {
                ite.erase(maxes.front().second);
                maxes.pop_front();
            }
            maxes.emplace_front(nums[i], i);
            ite[i] = maxes.begin();
        }

        for(int i=k; i<n; ++i) {
            res.push_back(maxes.back().first);
            if(ite.find(i-k) != ite.end()) {
                maxes.erase(ite[i-k]);
                ite.erase(i-k);
            }
            while(!maxes.empty() && maxes.front().first < nums[i]) {
                ite.erase(maxes.front().second);
                maxes.pop_front();
            }
            maxes.emplace_front(nums[i], i);
            ite[i] = maxes.begin();
        }
        res.push_back(maxes.back().first);
        return res;
    }
};