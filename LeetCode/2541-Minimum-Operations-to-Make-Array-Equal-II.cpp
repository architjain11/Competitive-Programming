class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0) {
            for(int i=0; i<nums1.size(); i++) {
                if(nums1[i]!=nums2[i]) return -1;
            }
            return 0;
        }
        long long ans=0, net=0, total=0;
        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i]==nums2[i]) continue;
            int diff=abs(nums1[i]-nums2[i]);
            if(diff%k==0) {
                total+=diff;
                net+=(nums1[i]-nums2[i]);
                if(net==0) {
                    ans+=total/(2*k);
                    total=0;
                }
            }
            else return -1;
        }
        if(net==0) return ans;
        return -1;
    }
};