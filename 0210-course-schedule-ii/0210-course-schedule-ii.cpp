class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& req) {
        int n = numCourses;
        int m = req.size();

        if (m > (n*(n-1))/2 ) return {};

        vector<int> topoOrder;
        topoOrder.reserve(n);

        int completed = 0;

        vector<int> head(n, -1);
        vector<int> nxt(m);
        vector<int> to(m);
        vector<int> deg(n);

        for(int i=0; i<m; ++i) {
            to[i] = req[i][0];
            nxt[i] = head[req[i][1]];
            head[req[i][1]] = i;
            deg[req[i][0]]++;
        }

        vector<int> stack;
        stack.reserve(n);

        for(int i = 0; i<n; ++i) {
            if(deg[i] == 0) stack.emplace_back(i);
        }

        while(!stack.empty()) {
            int curr = stack.back();
            stack.pop_back();
            topoOrder.emplace_back(curr);
            completed++;

            for(int e=head[curr]; e != -1; e=nxt[e]) {
                if(--deg[to[e]] == 0) stack.emplace_back(to[e]);
            }
        }

        if(completed != n) return {};
        return topoOrder;
    }
};