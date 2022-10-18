class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
    
        string str="1";
        
        for(int i=2; i<=n; i++) {
            string temp="";
            int count=1;
            str+="$";
            
            for(int j=1; j<str.length(); j++) {
                if(str[j]!=str[j-1]) {
                    temp+=to_string(count)+str[j-1];
                    count=1;
                }
                else count++;
            }
            
            str=temp;        
        }
        return str;
        
    }
};