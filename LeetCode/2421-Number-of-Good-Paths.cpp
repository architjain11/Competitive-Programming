class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        rank.resize(size, 0);
        parent.resize(size);
        for(int i=0; i<size; i++) parent[i]=i;
    }

    int find(int x) {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void makeunion(int x, int y) {
        int findx=find(x), findy=find(y);
        if(findx==findy) return;
        if(rank[findx]>rank[findy]) parent[findy]=findx;
        else if(rank[findx]<rank[findy]) parent[findx]=findy;
        else {
            parent[findx]=findy;
            rank[findy]++;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int a=edge[0], b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        map<int, vector<int>> m;
        for(int i=0; i<n; i++) m[vals[i]].push_back(i);

        UnionFind uf(n);
        int ans=0;

        for(auto& [value, nodes]: m) {
            for(auto& node: nodes) {
                for(auto adjacent: adj[node]) {
                    if(vals[node]>=vals[adjacent])
                        uf.makeunion(node, adjacent);
                }
            }

            map<int, int> group;
            for(auto& node: nodes) group[uf.find(node)]++;

            for(auto& [_, size]: group) ans+=(size*(size+1)/2);
        }
        
        return ans;
    }
};