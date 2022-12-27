class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> arr(capacity.size());
        transform(capacity.begin(), capacity.end(), rocks.begin(), arr.begin(), minus<int>());
        sort(arr.begin(), arr.end());

        int ans=0;
        for(auto x: arr) {
            if(x>additionalRocks) break;
            ans++;
            additionalRocks-=x;
        }
        return ans;
    }
};