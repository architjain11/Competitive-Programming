class Solution {
public:
    int setBits(int n) {
        int ans=0;
        while(n) {
            ans++;
            n&=(n-1);
        }
        return ans;
    }
    
    int minBitFlips(int start, int goal) {
        return(setBits(start^goal));
    }
};