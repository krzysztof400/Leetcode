class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        size_t len_of_strings = strs[0].size();
        for(int i = 0; i < len_of_strings; i++){
            for(int j = 0; j<strs.size()-1; j++){
                if((int)strs[j+1][i] < (int)strs[j][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};