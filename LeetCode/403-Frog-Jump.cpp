class Solution {
public:
    bool solve(int i, int jump, vector<int>& stones, vector<vector<int>>& cache) {
        if(i==stones.size()-1) return true;
        if(cache[i][jump]!=-1) return cache[i][jump];

        bool ans=false;
        for(int j=i+1; j<stones.size(); ++j) {
            if(stones[j]>stones[i]+jump+1) break;
            else if(stones[j]==stones[i]+jump-1)
                ans|=solve(j, jump-1, stones, cache);
            else if(stones[j]==stones[i]+jump)
                ans|=solve(j, jump, stones, cache);
            else if(stones[j]==stones[i]+jump+1)
                ans|=solve(j, jump+1, stones, cache);
        }
        return cache[i][jump]=ans;
    }

    bool canCross(vector<int>& stones) {
        vector<vector<int>> cache(stones.size(), vector<int>(2000, -1));
        return solve(0, 0, stones, cache);
    }
};