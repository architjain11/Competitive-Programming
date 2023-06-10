class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int emptyl=index, emptyr=n-index-1, r=maxSum, l=1;
        long long int ans=0;

        while(l<=r) {
            int mid=(r-l)/2+l;
            long long int leftSum=0, rightSum=0, ele=mid-1;
            
            if(emptyr<=ele)
                rightSum=(ele*(ele+1))/2 - ((ele-emptyr)*(ele-emptyr+1))/2;
            else
                rightSum=(ele*(ele+1))/2 + (emptyr-ele);
            
            if(emptyl<=ele)
                leftSum=(ele*(ele+1))/2 - ((ele-emptyl)*(ele-emptyl+1))/2;
            else
                leftSum=(ele*(ele+1))/2 + (emptyl-ele);

            long long int sum=leftSum+mid+rightSum;

            if(sum<=maxSum) {
                l=mid+1;
                ans=mid;
            } 
            else
                r=mid-1;   
        }
        return ans;
    }
};