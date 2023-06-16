class Solution {
public:
    vector<vector<long long>> table;
    long long mod=1e9+7;

    long long dfs(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 1;

        vector<int> leftSubtree, rightSubtree;
        for(int i=1; i<n; ++i)
            if(nums[i]<nums[0]) leftSubtree.push_back(nums[i]);
            else rightSubtree.push_back(nums[i]);

        long long l=dfs(leftSubtree)%mod, r=dfs(rightSubtree)%mod;
        return (((table[n-1][leftSubtree.size()]*l)%mod)*r)%mod;
    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        table.resize(n+1);

        for(int i=0; i<n+1; ++i) {
            table[i]=vector<long long>(i+1, 1);
            for(int j=1; j<i; ++j) {
                table[i][j]=(table[i-1][j-1]+table[i-1][j])%mod;
            }
        }

        long long ans=dfs(nums);
        return (ans%mod-1)%mod;
    }
};