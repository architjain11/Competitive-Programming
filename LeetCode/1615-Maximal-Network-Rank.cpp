class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
        unordered_map<int, unordered_set<int>> adj;
        
        for(auto& road: roads) {
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        for(int n1=0; n1<n; ++n1) {
            for(int n2=n1+1; n2<n; ++n2) {
                int currentRank=adj[n1].size()+adj[n2].size();
                if(adj[n1].find(n2)!=adj[n1].end())
                    --currentRank;
                ans=max(ans, currentRank);
            }
        }
        return ans;
    }
};