#define INF 1000000007
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INF);
        dp[0]=0;
        for(int i=1; i<=amount; i++) {
            for(auto c: coins) {
                if(i-c>=0) {
                    dp[i]=min(dp[i], dp[i-c]+1);                    
                }
            }
        }
        int ans = dp[dp.size()-1]!=INF?dp[dp.size()-1]:-1;
        return ans;
    }
};