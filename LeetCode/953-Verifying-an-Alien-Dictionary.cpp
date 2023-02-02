class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int, int> seq;
        for(int i=0; i<order.length(); i++) seq[order[i]]=i;
        for(int i=1; i<words.size(); i++) {
            string word1=words[i-1], word2=words[i];
            int j=0;
            while(j<word1.length()) {
                if(j>=word2.length()) return false;
                if(seq[word1[j]]<seq[word2[j]]) break;
                else if(seq[word1[j]]>seq[word2[j]]) return false;
                j++;
            }
        }
        return true;
    }
};