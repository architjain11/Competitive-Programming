class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged="";
        int m=word1.size(), n=word2.size(), i;
        for(i=0; i<m && i<n; ++i) {
            merged+=word1[i];
            merged+=word2[i];
        }
        while(i<m) {
            merged+=word1[i];
            ++i;
        }
        while(i<n) {
            merged+=word2[i];
            ++i;
        }
        return merged;
    }
};