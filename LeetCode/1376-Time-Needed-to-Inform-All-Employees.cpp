class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n; ++i)
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);

        queue<pair<int, int>> q;
        q.push({headID, 0});
        int ans=0;

        while(q.size()) {
            int id=q.front().first, time=q.front().second;
            q.pop();
            ans=max(ans, time);
            for(auto employee: adj[id])
                q.push({employee, time+informTime[id]});
        }

        return ans;
    }
};