class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& n1, vector<int>& n2, int k) {
        auto compare=[&](const vector<int>&a, const vector<int>&b) {
            return a[0]+a[1]>b[0]+b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

        vector<vector<int>> ans;
        if(n1.empty() || n2.empty() || k==1) return ans;

        for(int i=0; i<n1.size() && i<k; ++i)
            pq.push({n1[i], n2[0], 0});

        while(k-- && !pq.empty()) {
            vector<int> curr=pq.top();
            pq.pop();
            ans.push_back({curr[0], curr[1]});
            if(curr[2]==n2.size()-1) continue;
            pq.push({curr[0], n2[curr[2]+1], curr[2]+1});
        }
        return ans;
    }
};