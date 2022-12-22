class Solution {
public:
    void dfs0(int root, vector<int>& res, vector<int>& count, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[root]=true;
        for(auto& child: adj[root]) {
            if(!visited[child]) {
                dfs0(child, res, count, visited, adj);
                count[root]+=count[child];
                res[root]+=res[child]+count[child];
            }
        }
    }
    
    void dfs1(int root, vector<int>& res, vector<int>& count, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[root]=true;
        for(auto& child: adj[root]) {
            if(!visited[child]) {
            res[child]=res[root]-count[child]+count.size()-count[child];
            dfs1(child, res, count, visited, adj);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int a=edge[0], b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> res(n, 0), count(n, 1);
        vector<bool> visited(n, false);
        dfs0(0, res, count, visited, adj);
        visited.assign(n, false);
        dfs1(0, res, count, visited, adj);

        return res;
    }
};