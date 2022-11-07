class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> pairs;
        int n=nums.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int a=nums[i], b=nums[j];
                if(abs(a-b)==k) {
                    pair<int, int> temp{a,b};
                    if(a>b) swap(temp.first, temp.second);
                    pairs.insert(temp);                    
                }
            }
        }
        return pairs.size();
    }
};