class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        char a;

        for (auto &ch : s) {            
            if(ch=='{' || ch=='[' || ch=='(') {
                stack.push(ch);
                continue;
            }
            
            if(stack.empty())
                return false;
            
            switch(ch) {
                case ']':
                    a=stack.top();
                    stack.pop();
                    if(a=='{' || a=='(')
                        return false;
                    break;
                    
                case '}':
                    a=stack.top();
                    stack.pop();
                    if(a=='[' || a=='('){cout<<"this";
                        return false;}
                    break;
                    
                case ')':
                    a=stack.top();
                    stack.pop();
                    if(a=='{' || a=='[')
                        return false;
                    break;
                    
            }
        }
        return stack.empty();
    }
};