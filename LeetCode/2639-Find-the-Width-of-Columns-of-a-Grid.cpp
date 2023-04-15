class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) {
            int maxim=0;
            for(int j=0; j<m; j++) {
                string s=to_string(grid[j][i]);
                maxim = s.length()>maxim?s.length():maxim;
            }
            ans[i]=maxim;
        }
        
        return ans;
    }
};