class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<char> mappedTo;
        map<char,char> m;
        for(int i=0; i<s.size(); i++) {
            if(m.count(s[i]) || mappedTo.count(t[i])) {
                if(m[s[i]]!=t[i]) {
                    return false;
                }
            }
            else {
                m[s[i]]=t[i];
                mappedTo.insert(t[i]);
            }
        }
        return true;
    }
};