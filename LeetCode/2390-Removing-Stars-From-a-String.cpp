class Solution {
public:
    string removeStars(string s) {
        string temp="", ans="";
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='*') {
                int j=i;
                do {
                    if(temp=="") ans.erase(ans.end()-1);
                    else temp.erase(temp.end()-1);
                    j++;
                }while(s[j]=='*');
                i=j-1;
                ans+=temp;
                temp="";
            }
            else {
                temp+=s[i];
            }
        }
        return ans+temp;
    }
};