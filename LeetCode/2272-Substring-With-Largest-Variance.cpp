class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        unordered_map<char, int> freq;
        for(auto letter: s) freq[letter]++;

        for(char c1='a'; c1<='z'; ++c1) {
            for(char c2='a'; c2<='z'; c2++) {
                if(c1==c2 || !freq[c1] || !freq[c2]) continue;
                for(int rev=1; rev<=2; rev++) {
                    int cnt1=0, cnt2=0;
                    for(auto letter: s) {
                        cnt1 += letter==c1;
                        cnt2 += letter==c2;

                        if(cnt1<cnt2) cnt1=cnt2=0;

                        if(cnt1>0 && cnt2>0)
                            ans=max(ans, cnt1-cnt2);
                    }
                    reverse(s.begin(), s.end());
                }
            }
        }
        return ans;
    }
};