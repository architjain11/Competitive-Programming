class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        for(auto row: grid)
            m[row]++;
        int n=grid.size(), ans=0;
        for(int j=0; j<n; ++j) {
            vector<int> tmp;
            for(int i=0; i<n; ++i)
                tmp.push_back(grid[i][j]);
            ans+=m[tmp];
        }
        return ans;
    }
};