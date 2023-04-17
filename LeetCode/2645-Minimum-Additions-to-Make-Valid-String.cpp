class Solution {
public:
    int addMinimum(string word) {
        string letters="abc";
        int ans=0, i=0;
        
        for(int j=0; j<word.size();) {
            if(letters[i]==word[j]) j++;
            else ans++;
            i=(i+1)%3;
        }
        
        if(i==1) ans+=2;
        else if(i==2) ans+=1;
        
        return ans;
    }
};