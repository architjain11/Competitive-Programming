class Solution {
public:
    int dfs(int i, set<int>& visit, vector<vector<int>>& adj) {
        if(visit.count(i)) return 0;
        visit.insert(i);
        for(auto neighbour: adj[i])
            dfs(neighbour, visit, adj);
        return visit.size();
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(bombs.size());
        
        for(int i=0; i<bombs.size(); ++i) {
            for(int j=i+1; j<bombs.size(); ++j) {
                int x1=bombs[i][0], y1=bombs[i][1], r1=bombs[i][2];
                int x2=bombs[j][0], y2=bombs[j][1], r2=bombs[j][2];

                double dist=sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

                if(dist<=r1) adj[i].push_back(j);
                if(dist<=r2) adj[j].push_back(i);
            }
        }

        int ans=0;
        for(int i=0; i<bombs.size(); ++i) {
            set<int> visit;
            ans=max(ans, dfs(i, visit, adj));
        }

        return ans;
    }
};