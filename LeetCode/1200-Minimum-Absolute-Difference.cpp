class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int mindiff=INT_MAX, n=arr.size();
        for(int i=1; i<n; i++) mindiff=min(arr[i]-arr[i-1], mindiff);
        for(int i=1; i<n; i++)
            if(arr[i]-arr[i-1]==mindiff)
                ans.push_back({arr[i-1], arr[i]});
        return ans;
    }
};