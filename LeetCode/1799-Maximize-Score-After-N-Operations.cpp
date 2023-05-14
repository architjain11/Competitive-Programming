class Solution {
public:
    int dfs(vector<int>& nums, int mask, int op, vector<int>& cache) {
        int m=nums.size(), n=m/2;
        
        if(op>n) return 0;
        if(cache[mask]!=-1) return cache[mask];

        for(int i=0; i<m; ++i) {
            if(mask & (1<<i)) continue;

            for(int j=i+1; j<m; ++j) {
                if(mask & (1<<j)) continue;

                int newMask = mask | (1<<i) | (1<<j);
                int score=op*__gcd(nums[i], nums[j]) + dfs(nums, newMask, op+1, cache);
                cache[mask]=max(cache[mask], score);
            }
        }
        return cache[mask];
    }

    int maxScore(vector<int>& nums) {
        vector<int> cache(1<<14, -1);
        return dfs(nums, 0, 1, cache);
    }
};