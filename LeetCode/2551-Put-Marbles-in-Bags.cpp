class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> pairs;
        for(int i=0; i<n-1; ++i)
            pairs.push_back(weights[i]+weights[i+1]);
        sort(pairs.begin(), pairs.end());
        long long maxSum=0, minSum=0;
        for(int i=0; i<k-1; ++i) {
            maxSum+=pairs[n-i-2];
            minSum+=pairs[i];
        }
        return maxSum-minSum;
    }
};