class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        size_t size = strs[0].size();
        if (size == 1) { return 0; }
        vector<int> longest_subset_ending_at(size, 1);
        for (int i = 1; i< size; i++) {
            for ( int j = i -1; j>=0; j-- ) {
                if (can_add(strs, i, j)){
                    longest_subset_ending_at[i] = max(longest_subset_ending_at[j] + 1, longest_subset_ending_at[i]);
                }
            }
        }
        int max = 0;
        for(int val : longest_subset_ending_at){
            if(val > max){
                max = val;
            }
        }
        return size - max;
    }
    bool can_add(vector<string>& strs, int i, int j) {
        for ( const string& str : strs ) {
            if ( str[i] < str[j] ) {
                return false;
            }
        }
        return true;
    }
};