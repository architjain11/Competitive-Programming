class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int window = s1.length();
        map<char, int> m1, m2;
        for(auto letter: s1) m1[letter]++;
        for(int i=0; i<window; i++) m2[s2[i]]++;
        for(int i=window; i<s2.size(); i++) {
            if(m1==m2) return true;
            m2[s2[i]]++;
            if(m2[s2[i-window]]>1)
                m2[s2[i-window]]--;
            else
                m2.erase(s2[i-window]);
        }
        if(m1==m2) return true;
        else return false;        
    }
};