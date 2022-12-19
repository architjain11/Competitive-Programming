class Solution {
public:
    bool dfs(int source, int destination, vector<bool>& visited, vector<vector<int>>& adj) {
        if(source==destination) return true;
        if(visited[source]) return false;
        visited[source]=true;
        for(auto u: adj[source])
            if(dfs(u, destination, visited, adj)) return true;
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n);
        return dfs(source, destination, visited, adj);
    }
};