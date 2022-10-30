class Solution {
public:
    long long sumofdigits(long long n) {
        long long ans=0;
        while(n) {
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        long long original=n, zeroes=1;
        while(sumofdigits(n)>target) {
            long long temp=(10*zeroes-n%(10*zeroes));
            n+=temp;
            zeroes*=10;
        }
        
        return n-original;
    }
};