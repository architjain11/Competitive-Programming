class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqs(26), freqp(26), ans;
        for(auto letter: p) freqp[letter-'a']++;

        int low=0;
        for(int high=0; high<s.length(); high++) {
            freqs[s[high]-'a']++;
            if(high-low+1==p.size() && freqs==freqp) ans.push_back(low);
            if(high-low+1>=p.size()) {
                freqs[s[low]-'a']--;
                low++;
            }
        }
        return ans;
    }
};