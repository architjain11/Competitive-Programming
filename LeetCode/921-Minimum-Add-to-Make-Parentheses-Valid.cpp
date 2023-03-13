class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto parentheses: s) {
            if(parentheses==')' && !st.empty() && st.top()=='(') st.pop(); 
            else st.push(parentheses);
        }
        return st.size();
    }
};