class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(i==s1.size() && j==s2.size()) return 0;
        if(i==s1.size()) {
            int sum=0;
            for(; j<s2.size(); ++j)
                sum+=s2[j];
            return sum;
        }
        if(j==s2.size()) {
            int sum=0;
            for(; i<s1.size(); ++i)
                sum+=s1[i];
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=solve(i+1, j+1, s1, s2, dp);

        int a=s1[i]+solve(i+1, j, s1, s2, dp),
            b=s2[j]+solve(i, j+1, s1, s2, dp),
            c=s1[i]+s2[j]+solve(i+1, j+1, s1, s2, dp);
        return dp[i][j]=min({a, b, c});
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return solve(0, 0, s1, s2, dp);
    }
};