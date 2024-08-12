class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for(int i = 0; i<accounts.size(); i++){
            int score = 0;
            for(int j = 0; j<accounts[i].size(); j++){
                score += accounts[i][j];
                if(score>max){
                    max = score;
                }
            }
        }
        return max;
    }
};