class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long powerSum=accumulate(batteries.begin(), batteries.end(), 0LL);
        long long l=1, r=powerSum/n;

        while(l<r) {
            long long target=(l+r+1)/2;
            long long extra=0;

            for(auto power: batteries)
                extra+=min((long long)power, target);
            
            if(extra>=(long long)n*target)
                l=target;
            else r=target-1;
        }
        return l;
    }
};