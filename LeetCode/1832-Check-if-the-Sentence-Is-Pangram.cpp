class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> letter(26, 0);
        for(auto c: sentence) {
            letter[c-'a']++;
        }
        for(auto x: letter) 
            if(x==0) return false;
        return true;
    }
};