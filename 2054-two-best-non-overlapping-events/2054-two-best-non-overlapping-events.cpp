class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }

        int maxVal = 0;

        for (int i = 0; i < n; ++i) {
            maxVal = max(maxVal, events[i][2]);
            int endTime = events[i][1];
            
            int left = i + 1, right = n - 1, bestNextIdx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > endTime) {
                    bestNextIdx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (bestNextIdx != -1) {
                maxVal = max(maxVal, events[i][2] + suffixMax[bestNextIdx]);
            }
        }

        return maxVal;
    }
};