class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        long long ans=0;
        int l=0, r=costs.size()-1;

        while(k--) {
            while(l<=r && pq1.size()<candidates) {
                pq1.push(costs[l]);
                ++l;
            }
            while(l<=r && pq2.size()<candidates) {
                pq2.push(costs[r]);
                --r;
            }
            int a=pq1.size()?pq1.top():INT_MAX, b=pq2.size()?pq2.top():INT_MAX;
            if(b<a) {
                ans+=b;
                pq2.pop();
            }
            else {
                ans+=a;
                pq1.pop();
            }
        }
        return ans;
    }
};