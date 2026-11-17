class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const int& num : nums) {
            freq[num]++;
        }
        
        vector<vector<int>> buckets(nums.size()+1);
        for(const auto& [num, fq] : freq) {
            buckets[fq].push_back(num);
        }

        vector<int> res;
        res.reserve(k);

        for(int i = nums.size(); i>0; --i) {
            for(const int& num : buckets[i]) {
                if(res.size() == k) break;
                res.emplace_back(num);
            }
        }
        return res;
    }
};