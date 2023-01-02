class Solution {
public:
    bool detectCapitalUse(string word) {
        bool match=true;
        for(auto ch: word) {
            if(!isupper(ch)) {
                match=false;
                break;
            }
        }
        if(match) return match;

        match=true;
        for(int i=1; i<word.length(); i++) {
            if(!islower(word[i])) {
                match=false;
                break;
            }
        }
        return match;
    }
};