class Solution {
public:
    double time(vector<int>& dist, int speed) {
        double t=0.0;
        int n=dist.size();
        for(int i=0; i<n; ++i) {
            double tmp=(double)dist[i]/double(speed);
            t+=(i==n-1?tmp:ceil(tmp));
        }
        return t;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1, r=1e7, ans=-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(time(dist, mid)<=hour) {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};