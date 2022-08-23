class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(), ansLen=0;
        string ans;
        for(int i=0; i<n; i++) {
            int left=i, right=i;
            while(left>=0 && right<n && s[left]==s[right]) {
                if(right-left+1>ansLen){
                    ansLen=right-left+1;
                    ans=s.substr(left, ansLen);
                }
                left--; right++;
            }
            
            left=i; right=i+1;
            while(left>=0 && right<n && s[left]==s[right]) {
                if(right-left+1>ansLen){
                    ansLen=right-left+1;
                    ans=s.substr(left, ansLen);
                }
                left--; right++;
            }
        }
        return ans;
    }
    
};