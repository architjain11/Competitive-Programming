class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i]!=']') st.push(s[i]);
            else {
                string substring="";
                while(st.top()!='[') {
                    substring=st.top()+substring;
                    st.pop();
                }
                st.pop();
                string k="";
                while(!st.empty() && isdigit(st.top())) {
                    k=st.top()+k;
                    st.pop();                    
                }
                string word=substring;
                int temp=stoi(k)-1;
                while(temp--) substring+=word;  
                for(auto x: substring) st.push(x);           
            }
        }
        string ans="";
        while(!st.empty()) {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};