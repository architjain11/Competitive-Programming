class Solution {
public:
    int find(int x, vector<int>& parent) {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x], parent);
    }

    void makeunion(int x, int y, vector<int>& parent) {
        int find1=find(x, parent), find2=find(y, parent);
        if(find1==find2) return;
        if(find1<find2) parent[find2]=find1;
        else parent[find1]=find2;  
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i=0; i<26; i++) parent[i]=i;
        for(int i=0; i<s1.length(); i++) makeunion(s1[i]-'a', s2[i]-'a', parent);
        
        for(auto c: parent) cout<<c<<" ";

        string ans;
        for(auto x: baseStr) ans+=(char)(find(x-'a', parent)+'a');
        return ans;
    }
};