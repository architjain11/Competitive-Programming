class Solution {
public:
    string reverseWords(string s) {
        string ans="", tmp="";
        for(auto letter: s) {
            if(letter==' ') {
                reverse(tmp.begin(), tmp.end());
                ans+=(tmp+' ');
                tmp="";
                continue;
            }
            tmp+=letter;
        }
        reverse(tmp.begin(), tmp.end());
        ans+=tmp;
        return ans;
    }
};