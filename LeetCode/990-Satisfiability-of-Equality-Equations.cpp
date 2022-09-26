class Solution {
public:
    vector<int> group;
    int findroot(int a) {
        return group[a]==a?a:findroot(group[a]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i<26; i++) group.push_back(i);
        
        for(auto eqn: equations) {
            if(eqn[1]=='=') {
                int a=findroot(eqn[0]-'a');                
                int b=findroot(eqn[3]-'a');
                if(a!=b) {
                    group[a]=b;
                }
            }
        }
        
        for(auto eqn: equations) {
            if(eqn[1]=='!') {
                int a=findroot(eqn[0]-'a');
                int b=findroot(eqn[3]-'a');
                if(a==b) {
                    return false;
                }
            }
        }
        return true;
    }
};