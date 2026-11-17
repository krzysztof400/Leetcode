class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int m = prerequisites.size();

        if (m > (n*(n+1))/2) return false;
        // CSR and check for max edges size
        int completed = 0;
        
        vector<vector<int>> adj(n);
        vector<int> degrees(n);

        for(const vector<int>& req : prerequisites) {
            adj[req[1]].emplace_back(req[0]);
            degrees[req[0]]++;
        }
        queue<int> Q;
        for(int i =0; i<n; ++i) {
            if(degrees[i] == 0) {
                Q.push(i);
            }
        }
        while(!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            completed++;
            for(int& nei : adj[curr]) {
                if(--degrees[nei] == 0) {
                    Q.push(nei);
                } 
            }
        }
        return completed == n;
    }
};