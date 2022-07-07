class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0], max_diff=0;
        for(int i=0; i<prices.size(); i++) {
            min = min>prices[i] ? prices[i] : min;
            max_diff = max_diff>prices[i]-min ? max_diff : prices[i]-min;
        }
        return max_diff;
    }
};