class Solution {
public:
    vector<int> dfs(int node, int parent, vector<vector<int>>& adj, string& labels, vector<int>& ans) {
        vector<int> nodecount(26);
        nodecount[labels[node]-'a']=1;
        for(auto& child: adj[node]) {
            if(child==parent) continue;
            vector<int> childcount=dfs(child, node, adj, labels, ans);
            for(int i=0; i<26; i++)
                nodecount[i]+=childcount[i];
        }
        ans[node]=nodecount[labels[node]-'a'];
        return nodecount;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int a=edge[0], b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> ans(n);
        dfs(0, -1, adj, labels, ans);
        return ans;
    }
};