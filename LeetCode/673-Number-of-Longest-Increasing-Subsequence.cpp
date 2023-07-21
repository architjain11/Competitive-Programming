class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        unordered_map<int, pair<int, int>> dp; //index->{list length, count}
        int lenList=0, ans=0;

        for(int i=nums.size()-1; i>=0; --i) {
            int maxLen=1, maxCount=1;
            for(int j=i+1; j<nums.size(); ++j) {
                if(nums[j]>nums[i]) {
                    int length=dp[j].first, count=dp[j].second;
                    if(length+1>maxLen) {
                        maxLen=length+1;
                        maxCount=count;
                    }
                    else if(length+1==maxLen)
                        maxCount+=count;
                }
            }
            if(maxLen>lenList) {
                lenList=maxLen;
                ans=maxCount;
            }
            else if(maxLen==lenList)
                ans+=maxCount;
            dp[i]={maxLen, maxCount};
        }
        return ans;
    }
};