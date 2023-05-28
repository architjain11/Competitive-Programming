class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        unordered_set<int> s;
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                s.clear();
                for(int k=i+1, l=j+1; k<m && l<n; ++k, ++l) s.insert(grid[k][l]);    
                int bottomRight=s.size();
                
                s.clear();
                for(int k=i-1, l=j-1; k>=0 && l>=0; --k, --l) s.insert(grid[k][l]);
                int topLeft=s.size();
                
                ans[i][j]=abs(topLeft-bottomRight);                
            }
        }
        
        return ans;
    }
};