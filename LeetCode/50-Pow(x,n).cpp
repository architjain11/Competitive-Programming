class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) {
            x=1/x;
            n=abs(n);
        }

        double ans=1;
        while(n>0) {
            if(n%2==0) {
                x*=x;
                n/=2;
            }
            else {
                ans=ans*x;
                n--;
            }
        }

        return ans;
    }
};