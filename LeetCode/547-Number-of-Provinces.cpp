class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(parent[x]!=x)
            return parent[x]=find(parent[x]);
        else return x;
    }

    void Union(int x, int y) {
        parent[find(y)]=find(x);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i]=i;

        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(isConnected[i][j])
                    Union(i, j);
        
        int ans=0;
        for(int i=0; i<n; ++i)
            if(parent[i]==i) ans++;
        return ans;
    }
};