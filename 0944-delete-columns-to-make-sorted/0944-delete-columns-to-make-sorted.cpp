class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for(int i = 0; i< strs[0].size(); i++){
            for(int j = 0; j<strs.size()-1; j++){
                if((int)strs[j+1][i] - (int)strs[j][i] < 0){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
    bool isSortedLex(string str, int len_of_string){
        for(int i = 0; i<len_of_string-1; i++){
            if((int)str[i+1] - (int)str[i] < 0){
                return false;
            }
        }
        return true;
    }
};