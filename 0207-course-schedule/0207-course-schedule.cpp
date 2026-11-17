class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int m = prerequisites.size();

        if (m > (n*(n+1))/2) return false;
        int completed = 0;
        
        vector<vector<int>> adj(n);

        vector<int> head(n, -1);
        vector<int> nxt(m);
        vector<int> to(m);
        vector<int> degrees(n);        

        for(int i = 0; i<m; ++i) {
            to[i] = prerequisites[i][0];
            nxt[i] = head[prerequisites[i][1]];
            head[prerequisites[i][1]] = i;
            degrees[prerequisites[i][0]]++;
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
            for(int e = head[curr]; e != -1; e = nxt[e]) {
                if(--degrees[to[e]] == 0) {
                    Q.push(to[e]);
                } 
            }
        }
        return completed == n;
    }
};