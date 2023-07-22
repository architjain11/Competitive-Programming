class Solution {
public:
    bool vowel(char c) {
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;
        vector<char> vowels;
        for(auto ele: s) 
            if(vowel(ele))
               pq.push(ele);
        
        for(int i=0; i<s.size(); ++i) {
            if(vowel(s[i])) {
                s[i]=pq.top();
                pq.pop();
            }
        }
        
        return s;
        
    }
};