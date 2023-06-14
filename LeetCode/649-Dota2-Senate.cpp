class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.length();
        queue<int> r, d;

        for(int i=0; i<n; ++i) {
            if(senate[i]=='R')
                r.push(i);
            else d.push(i);
        }

        while(!r.empty() && !d.empty()) {
            int dtop=d.front(), rtop=r.front();
            d.pop(); r.pop();

            if(dtop<rtop)
                d.push(dtop+n);
            else r.push(rtop+n);
        }

        return r.empty()?"Dire":"Radiant";        
    }
};