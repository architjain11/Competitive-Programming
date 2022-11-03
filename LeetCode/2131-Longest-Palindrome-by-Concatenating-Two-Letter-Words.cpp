class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_multiset<string> s;
        int ans=0;
        for(auto word: words) {
            if(s.count(word)) {
                ans+=4;
                s.erase(s.find(word));
            }
            else {
                reverse(word.begin(), word.end());
                s.insert(word);
            }
        }
        
        for(auto it=s.begin(); it!=s.end(); it++) {
            if((*it)[0]==(*it)[1]) {
                ans+=2;
                break;
            }
        }
        return ans;
    }
};