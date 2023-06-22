class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> buy(n, 0), sell(n, 0);
        buy[0]=-prices[0];

        for(int i=1; i<n; ++i) {
            sell[i]=max(sell[i-1], buy[i-1]+prices[i]-fee);
            buy[i]=max(buy[i-1], sell[i-1]-prices[i]);
        }
        return sell[n-1];
    }
};