class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<int> ans;

        for(int i=0; i<n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        long time=0;
        int i=0;

        while(i<n || pq.size()) {
            if(pq.empty()) time=max(time, (long)tasks[i][0]);
            while(i<n && time>=tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            pair<int, int> tmp=pq.top();
            ans.push_back(tmp.second);
            time+=tmp.first;
            pq.pop();
        }
        return ans;
    }
};