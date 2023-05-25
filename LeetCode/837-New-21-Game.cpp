class Solution {
public:
    double new21Game(int n, int k, int maxpts) {
        if(k==0 || k+maxpts<=n) return 1.0;
        
        double winsum=0;
        for(int i=k; i<k+maxpts; ++i)
            winsum+=(i<=n?1:0);
        
        unordered_map<int, double> dp;
        for(int i=k-1; i>=0; --i) {
            dp[i]=(double)winsum/maxpts;
            double remove=0;
            if(i+maxpts<=n)
                remove=(dp.count(i+maxpts)==0?1:dp[i+maxpts]);
            winsum+=dp[i]-remove;
        }

        return dp[0];
    }
};