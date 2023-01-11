class Solution {
public:
    int dfs(vector<bool>& hasApple, vector<vector<int>>& adj, int node, int parent) {
        int ans=0, childt=0;
        for(auto& child: adj[node]) {
            if(child==parent) continue;
            childt=dfs(hasApple, adj, child, node);
            if(hasApple[child] || childt) ans+=childt+2;
        }
        return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int a=edge[0], b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return dfs(hasApple, adj, 0, -1);
    }
};