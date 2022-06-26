class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x) {
            if(ans <= INT_MAX/10 && ans >=INT_MIN/10) {
                ans = ans*10 + (x%10);
                x/=10;
            }
            else
                return 0;
        }
        
        return ans;
    }
};