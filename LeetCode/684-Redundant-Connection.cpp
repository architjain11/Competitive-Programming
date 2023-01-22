class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int size) {
        parent.resize(size+1);
        for(int i=0; i<size; i++) parent[i]=i;
    }

    int find(int x) {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void makeUnion(int x, int y) {
        parent[find(y)]=find(x);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        for(auto& edge: edges) {
            int x=edge[0], y=edge[1];
            if(uf.find(x)==uf.find(y)) return {x,y};
            uf.makeUnion(x, y);
        }
        return {0,0};
    }
};