class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;

        for(int i=0; i<path.size(); i++) {
            if(path[i]=='/') continue;
            string tmp="";
            while(i<path.size() && path[i]!='/') {
                tmp+=path[i];
                ++i;
            }
            if(tmp==".") continue;
            else if(tmp=="..") {
                if(!s.empty()) s.pop();
            }
            else s.push(tmp);
        }
        string ans="/";
        while(!s.empty()) {
            ans="/"+s.top()+ans;
            s.pop();
        }
        if(ans.length()>1) ans.erase(ans.end()-1);
        return ans;
    }
};