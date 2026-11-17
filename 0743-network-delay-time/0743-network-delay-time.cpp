class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> neig(n+1);
        vector<int> cost(n+1, INT_MAX);
        vector<bool> visited(n+1, 0);

        int result = 0;
        for(int i = 0; i<times.size(); i++) {
            neig[times[i][0]].emplace_back(times[i][1], times[i][2]); // from neig[i] to v with w
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        pq.emplace(0, k);
        cost[k] = 0;
        while(!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();
            if(visited[node]) continue;
            // printf("node: %d, weight: %d\n", node, weight);
            for(const auto& nei : neig[node]) {
                if(!visited[nei.first]) {
                    cost[nei.first] = min(cost[nei.first], weight + nei.second);
                    pq.emplace(cost[nei.first], nei.first);
                }
            }
            visited[node] = true;
        }
        for (int i = 1; i<n+1; ++i) {
            if (!visited[i]) {
                return -1;
            }
        }
        // for(const int& wei : cost) {
        //     printf("%d, ", wei);
        // }
        return *max_element(cost.begin()+1, cost.end());
    }
};