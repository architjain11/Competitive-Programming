class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0]=1;

        for(int i=coins.size()-1; i>=0; --i) {
            vector<int> nextdp(amount+1, 0);
            nextdp[0]=1;
            for(int j=1; j<=amount; ++j) {
                nextdp[j]=dp[j];
                if(j-coins[i]>=0)
                    nextdp[j]+=nextdp[j-coins[i]];
            }
            dp=nextdp;
        }
        return dp[amount];
    }
};