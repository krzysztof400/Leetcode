class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int best_time = INT_MAX;
        int n = landDuration.size();
        int m = waterDuration.size();
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j< m; ++j) {
                int time = 0;
                if (waterStartTime[j] > landStartTime[i]) {
                    time = landStartTime[i] + landDuration[i];
                    if(time < waterStartTime[j]) {
                        time = waterStartTime[j] + waterDuration[j];
                    }
                    else {
                        time += waterDuration[j];
                    }
                }
                else {
                    time = waterStartTime[j] + waterDuration[j];
                    if(time < landStartTime[i]) {
                        time = landStartTime[i] + landDuration[i];
                    }
                    else {
                        time += landDuration[i];
                    }
                }
                best_time = min(time, best_time);                
            }
        }
        return best_time;
    }
};