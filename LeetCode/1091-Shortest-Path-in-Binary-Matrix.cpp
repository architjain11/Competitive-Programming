class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        grid[0][0] = -1;
        int path = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while(q.size()) {
            int k = q.size();
            path++;

            while(k--) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x==n-1 && y==n-1) return path;

                vector<int> distX = {0, 0, 1, 1, 1, -1, -1, -1};
                vector<int> distY = {1, -1, 1, -1, 0, -1, 0, 1};

                for(int i=0; i<8; ++i) {
                    int newX = x+distX[i], newY = y+distY[i];
                    if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==0) {
                        grid[newX][newY]=1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return -1;
        
    }
};