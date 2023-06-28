class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); ++i) {
            int u=edges[i][0], v=edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        vector<double> dist(n, 0.0);
        dist[start]=1;

        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int curr=q.front();
            q.pop();
            for(auto u: adj[curr]) {
                int node=u.first;
                double newProb=dist[curr]*u.second;
                if(newProb>dist[node]) {
                    dist[node]=newProb;
                    q.push(node);
                }
            }
        }
        
        return dist[end];
    }
};