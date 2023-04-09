class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n=nums.size();        
        vector<long long> arr(n), pre(n), suf(n);
        unordered_map<int, vector<int>> m;
        
        for(int i=0; i<n; i++) m[nums[i]].push_back(i);

        for(auto& [num, indices]: m) {
            long long sum=indices[0];
            for(int i=1; i<indices.size(); ++i) {
                pre[indices[i]]=abs((long long)i*indices[i]-sum);
                sum+=indices[i];
            }
        }

        for(auto& [num, indices]: m) {
            int isize=indices.size();
            long long sum=indices[isize-1];
            for(int i=isize-2; i>=0; --i) {
                suf[indices[i]]=abs((long long)(isize-i-1)*indices[i]-sum);
                sum+=indices[i];
            }
        }

        for(int i=0; i<n; i++) arr[i]=pre[i]+suf[i];

        return arr;
    }
};