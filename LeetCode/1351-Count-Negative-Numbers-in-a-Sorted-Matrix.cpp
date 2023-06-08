class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=grid.size()-1, j=grid[0].size()-1, ans=0;

        while(i>=0) {
            if(grid[i][j]<0)
                ans++;
            if(j==0) {
                i--;
                j=grid[0].size()-1;
            }
            else
                j--;   
        }
        return ans;
    }
};