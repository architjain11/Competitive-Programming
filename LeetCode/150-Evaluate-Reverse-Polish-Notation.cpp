class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long int> s;
        for(auto x: tokens) {
            if(x!="*" && x!="/" && x!="+" && x!="-") {
                s.push(stoi(x));
            }
            else {
                long int b=s.top();
                s.pop();
                long int a=s.top();
                s.pop();
                long int ans;
                if(x=="+") ans=a+b;
                else if(x=="-") ans=a-b;
                else if(x=="*") ans=a*b;
                else ans=trunc(a/b);
                s.push(ans);
            }
        }
        return s.top();
    }
};