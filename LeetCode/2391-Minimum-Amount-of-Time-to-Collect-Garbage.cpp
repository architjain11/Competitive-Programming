class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time=0;
        
        for(int i=0; i<garbage.size(); i++) {
            time+=garbage[i].length();
        }
        
        vector<int> prefix(travel.size()+1, 0);
        for(int i=1; i<prefix.size(); i++) prefix[i]=travel[i-1]+prefix[i-1];
        
        
        int p=0, m=0, g=0;        
        for(int i=garbage.size()-1; i>=0; i--) {
            for(auto c: garbage[i]) {
                if(c=='P' && p==0) {
                    p=1;
                    time+=prefix[i];
                }
                else if(c=='G' && g==0) {
                    g=1;
                    time+=prefix[i];
                }
                else if(c=='M' && m==0) {
                    m=1;
                    time+=prefix[i];
                }
            }
            if(p==1 && g==1 && m==1) break;
        }
        return time;
    }
};