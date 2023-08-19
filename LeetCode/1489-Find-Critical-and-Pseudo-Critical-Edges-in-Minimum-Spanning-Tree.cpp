class dsu {
public:
    vector<int> parent, rank;

    dsu(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0; i<n; ++i)
            parent[i]=i;
    }

    int find(int x) {
        return parent[x]=(parent[x]==x?x:find(parent[x]));
    }

    bool Union(int x, int y) {
        int xpar=find(x), ypar=find(y);
        if(xpar!=ypar) {
            rank[xpar]<rank[ypar]?parent[xpar]=ypar:parent[ypar]=xpar;
            rank[xpar]+=rank[xpar]==rank[ypar];
            return true;
        }
        return false;
    }

};

int getMST(int n, vector<vector<int>>& edges, int excl=-1, int incl=-1) {
    dsu dsu(n);
    int weight=0;
    if(incl!=-1) {
        weight+=edges[incl][2];
        dsu.Union(edges[incl][0], edges[incl][1]);
    }

    for(int i=0; i<edges.size(); ++i) {
        if(i==excl) continue;
        auto& edge=edges[i];
        if(dsu.find(edge[0])==dsu.find(edge[1])) continue;
        dsu.Union(edge[0], edge[1]);
        weight+=edge[2];
    }
    
    for(int i=0; i<n; ++i) {
        if(dsu.find(i)!=dsu.find(0))
            return 1e9+7;
    }
    return weight;
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0; i<edges.size(); ++i)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2]<b[2];
        });
        int original=getMST(n, edges, -1);
        vector<int> critical, non_critical;
        for(int i=0; i<edges.size(); ++i) {
            if(original<getMST(n, edges, i))
                critical.push_back(edges[i][3]);
            else if(original==getMST(n, edges, -1, i))
                non_critical.push_back(edges[i][3]);
        }
        return {critical, non_critical};
    }
};