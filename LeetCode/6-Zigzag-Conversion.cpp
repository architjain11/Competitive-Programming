class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans;
        int a=0, flag=0; //0 is up and 1 is down
        
        if(numRows==1)
            return s;
        
        for(int i=0; i<numRows; i++)
            ans.push_back("");
        
        for(int i=0; i<s.length(); i++) {
            ans[a].append(1, s[i]);
            
            if(flag==0) {
                a++;
                if(a==numRows-1)
                    flag=1;
            }
            else {
                a--;
                if(a==0)
                    flag=0;
            }
        }
        
        string answer="";
        for(int i=0; i<numRows; i++)
            answer.append(ans[i]);
        return answer;
    }
};