class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        for(int i=0; i<letters.size(); ++i) {
            cout<<(target)-'a'<<endl;
            if(letters[i]>=target+1) {
                ans=letters[i];
                break;
            }
        }
        return ans;
    }
};