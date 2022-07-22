class Solution {
public:
    bool isSubsequence(string s, string t) {
        int travel=0;
        for(int i=0; i<t.size() && travel<s.size(); i++) {
            if(s[travel]==t[i])
                travel++;
        }
        return travel==s.size()?true:false;
    }
};