class Solution {
public:
    bool isPalindrome(int n) {
        if(n<0)
            return false;
        int divisor=1;
        while(n / divisor >= 10)
            divisor *= 10;
        
        while(n!=0) {
            int start = n/divisor, last = n%10;
            if(start!=last)
                return false;
            
            n=(n%divisor)/10;
            divisor/=100;
        }
        return true;
        
    }
};