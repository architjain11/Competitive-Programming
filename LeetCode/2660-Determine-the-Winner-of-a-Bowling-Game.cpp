class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int p1=0, p2=0, dbl1=0, dbl2=0;
        for(int i=0; i<player1.size(); ++i) {
            int a=player1[i], b=player2[i];
            p1+=a;
            if(dbl1) {
                p1+=a;
                --dbl1;
            }
            if(a==10) dbl1=2;

            p2+=b;
            if(dbl2) {
                p2+=b;
                --dbl2;
            }
            if(b==10) dbl2=2;
        }
        
        if(p1==p2) return 0;
        else return p1>p2?1:2;
    }
};