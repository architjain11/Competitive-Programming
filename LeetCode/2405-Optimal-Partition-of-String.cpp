class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> m;
        int ans=0;
        for(auto letter: s) {
            if(m[letter]) {
                ans++;
                for(auto [k,v]: m) cout<<k<<" ";
                cout<<endl;
                m.clear();
            }
            m[letter]++;
        }
        if(m.empty()) return ans;
        else return ans+1;
    }
};