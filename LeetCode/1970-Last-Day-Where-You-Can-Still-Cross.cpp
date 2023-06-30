class Solution {
public:
    bool walk(vector<vector<int>>& cells, int row, int col, int day) {
        vector<int> dx={0, 0, -1, 1},
                    dy={1, -1, 0, 0};
        vector<vector<bool>> grid(row, vector<bool>(col, 0));
        for(int i=0; i<day; ++i)
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        
        queue<pair<int, int>> q;
        for(int i=0; i<col; ++i) {
            if(!grid[0][i]) {
                q.push({0, i});
                grid[0][i]=1;
            }
        }

        while(!q.empty()) {
            auto [r, c]=q.front();
            q.pop();
            if(r==row-1) return true;
            for(int i=0; i<4; ++i) {
                int nr=r+dx[i], nc=c+dy[i];
                if(nr<0 || nr==row || nc<0 || nc==col || grid[nr][nc]==1) continue;
                grid[nr][nc]=1;
                q.push({nr, nc});
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=1, right=cells.size(), ans=0;
        while(left<=right) {
            int mid=(right+left)/2;
            if(walk(cells, row, col, mid)) {
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return ans;
    }
};