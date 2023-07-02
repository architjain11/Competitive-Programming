class Solution {
public:
    int ans=INT_MIN;

    void solve(int i, vector<vector<int>>& requests, vector<int>& building, int reqDone) {
        if(i==requests.size()) {
            for(auto x: building)
                if(x!=0) return;
            ans=max(ans, reqDone);
            return;
        }

        solve(i+1, requests, building, reqDone);
        building[requests[i][0]]--;
        building[requests[i][1]]++;
        solve(i+1, requests, building, reqDone+1);
        building[requests[i][0]]++;
        building[requests[i][1]]--;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> building(n, 0);
        solve(0, requests, building, 0);
        return ans;
    }
};