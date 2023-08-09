class Solution {
public:
    string finalString(string s) {
        string ans="";
        for(auto letter: s) {
            if(letter=='i')
                reverse(ans.begin(), ans.end());
            else
                ans+=letter;
        }
        return ans;
    }
};