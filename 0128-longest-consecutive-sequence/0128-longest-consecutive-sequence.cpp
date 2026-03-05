class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_map (nums.begin(), nums.end());

        int max_len = 0;
        int current_len = 0;
        int current_num;
        
        for(int num : hash_map) {
            if( hash_map.find(num - 1) == hash_map.end() ) {
                current_len = 1;
                current_num = num + 1;

                while (hash_map.find(current_num) != hash_map.end()) {
                    current_num++;
                    current_len++;
                }

                max_len = max(max_len, current_len);
            }
        }
        return max_len;

        return max_len;
    }
};