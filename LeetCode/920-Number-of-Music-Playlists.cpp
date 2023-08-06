class Solution {
public:
    int mod=1e9+7;

    long long helper(int goal, int used, int n, int k, vector<vector<int>>& dp) {
        if(goal==0 && used==n) return 1;
        if(goal==0 || used>=n) return 0;
        if(dp[used][goal]!=-1) return dp[used][goal];

        long long newSong=helper(goal-1, used+1, n, k, dp)*(n-used);
        long long oldSong=helper(goal-1, used, n, k, dp)*max(n-used-k, 0);
        return dp[used][goal]=(newSong+oldSong)%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n+1, vector<int>(goal+1, -1));
        return helper(goal, 0, n, k, dp);
    }
};