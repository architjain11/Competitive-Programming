class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int length=strs[0].length();
        set<int> index;

        for(int i=0; i<length; i++) {
            char prev='a';
            for(auto word: strs) {
                if(word[i]<prev) {
                    index.insert(i);
                    break;
                }
                else prev=word[i];
                    
            }
        }
        return index.size();
    }
};