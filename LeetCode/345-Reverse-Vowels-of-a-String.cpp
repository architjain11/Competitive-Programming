class Solution {
public:
    bool isvowel(char n) {
        n=tolower(n);
        vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for(auto x: vowels) if(x==n) return true;
        return false;
    }
    string reverseVowels(string s) {
        string temp="";
        for(auto x: s) if(isvowel(x)) temp+=x;
        reverse(temp.begin(), temp.end());
        int point=0;
        for(int i=0; i<s.size(); i++) {
            if(isvowel(s[i])) {
                s[i]=temp[point];
                point++;
            }
        }
        return s;
    }
};