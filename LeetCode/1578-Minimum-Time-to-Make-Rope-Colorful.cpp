class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length(), ans=0;
        for(int i=0; i<n; ) {
            int j=i, sum=0, maximum=0;
            while(i<n && colors[i]==colors[j]) {
                sum+=neededTime[i];
                maximum=max(maximum, neededTime[i]);
                i++;
            }
            ans+=sum-maximum;
        }
        return ans;
    }
};