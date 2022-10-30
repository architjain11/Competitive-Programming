class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, priority_queue<pair<long long int, string>>> m;
        int n=creators.size();
        map<string, long long int> popularity;
        
        for(int i=0; i<n; i++) {
            m[creators[i]].push({views[i], ids[i]});
            popularity[creators[i]]+=views[i];
        }
        
        long long int highest_popularity=-1;
        for(auto x: popularity) {
            highest_popularity=max(highest_popularity, x.second);
        }
                
        vector<vector<string>> ans;
        
        for(auto c: popularity) {
            string creator=c.first;
            if(popularity[creator]==highest_popularity) {
                priority_queue<string, vector<string>, greater<string>> temp;
                int max_views=m[creator].top().first;
                while(!m[creator].empty() && m[creator].top().first==max_views) {
                    temp.push(m[creator].top().second);
                    m[creator].pop();
                }
                ans.push_back({creator, temp.top()});
            }
        }
        
        return ans;
    }
};