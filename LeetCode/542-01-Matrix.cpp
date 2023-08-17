class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(!mat[i][j])
                    q.push({i, j});

        int dist=0;
        while(!q.empty()) {
            dist++;
            int k=q.size();
            while(k--) {
                auto pos=q.front();
                int x=pos.first, y=pos.second;
                q.pop();
                vector<int> dx={1, -1, 0, 0},
                            dy={0, 0, 1, -1};
                for(int i=0; i<4; ++i) {
                    int newX=x+dx[i], newY=y+dy[i];
                    if(newX>=0 && newX<n && newY>=0 && newY<m && mat[newX][newY]) {
                        mat[newX][newY]=0;
                        ans[newX][newY]=dist;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return ans;
    }
};