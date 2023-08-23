class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26);
        for(auto c: s) count[c-'a']++;

        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; ++i)
            if(count[i]) pq.push({count[i], i+'a'});

        string ans;
        while(!pq.empty()) {
            auto first=pq.top(); pq.pop();
            if(ans.length()==0 || first.second!=ans.back()) {
                if(ans.length()) cout<<first.second<<ans[ans.length()-1]<<endl;
                ans+=first.second;
                if(--first.first>0) pq.push(first);
            }
            else {
                if(pq.empty()) return "";
                auto second=pq.top(); pq.pop();
                ans+=second.second;
                if(--second.first>0) pq.push(second);
                pq.push(first);
            }
        }
        return ans;        
    }
};