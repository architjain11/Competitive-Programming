class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& adj, vector<int>& colors) {
        colors[node]=color;
        for(auto& person: adj[node]) {
            if(colors[person]==color) return false;
            if(colors[person]==-1)
                if(!dfs(person, 1-color, adj, colors)) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto& dislike: dislikes) {
            int a=dislike[0], b=dislike[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> colors(n+1, -1);
        for(int i=1; i<=n; i++)
            if(colors[i]==-1)
                if(!dfs(i, 0, adj, colors)) return false;
        
        return true;
    }
};