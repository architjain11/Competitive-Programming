class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), 0);
        for(int j=0; j<grid[0].size(); j++) {
            int currcol=j;
            for(int i=0; i<grid.size(); i++) {
                int nextcol=currcol+grid[i][currcol];
                if(nextcol<0 || nextcol>grid[0].size()-1 || grid[i][currcol]!=grid[i][nextcol]) {
                    ans[j]=-1;
                    break;
                }
                ans[j]=nextcol;
                currcol=nextcol;
            }
        }
        return ans;
    }
};