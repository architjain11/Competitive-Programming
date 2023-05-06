class Solution {
public:
    bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int maxv=0, currv=0, start=0, end=0;
        while(end<s.length()) {
            while(end<k) {
                if(isVowel(s[end])) currv++;
                end++;
                maxv=max(maxv, currv);
            }
            if(isVowel(s[end])) currv++;
            if(isVowel(s[start])) currv--;
            start++; end++;
            maxv=max(maxv, currv);
        }

        return maxv;
    }
};