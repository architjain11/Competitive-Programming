class Solution {
public:
    unordered_map<string, double> dp;
    int dir[8][8]={{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    
    double find(int n, int k, int r, int c) {
        if(r>=n || c>=n || r<0 || c<0) return 0;
        if(k==0) return 1;

        string key=to_string(r)+"A"+to_string(c)+"J"+to_string(k);
        if(dp.count(key)) return dp[key];

        double prob=0;
        for(int i=0; i<8; ++i)
            prob+=find(n, k-1, r+dir[i][0], c+dir[i][1])/8.0;
        return dp[key]=prob;
    }


    double knightProbability(int n, int k, int row, int column) {
        return find(n, k, row, column);
    }
};