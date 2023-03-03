class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n=ideas.size();
        unordered_map<char, unordered_set<string>> m;
        for(auto idea: ideas) m[idea[0]].insert(idea.substr(1, idea.size()-1));

        long long ans=0;
        for(auto it=m.begin(); it!=m.end(); it++) {
            for(auto it2=next(it); it2!=m.end(); it2++) {
                int mutual=0;
                for(auto v: it->second) {
                    if(it2->second.count(v)) mutual++;
                }
                ans+=2*(it->second.size()-mutual)*(it2->second.size()-mutual);
            }
        }
        
        return ans;
    }
};