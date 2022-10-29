class Solution {
public:
    string oddString(vector<string>& words) {
        int n=words[0].size(), flag=0;
        vector<vector<int>> diff;
        
        for(int i=0; i<words.size(); i++) {
            vector<int> temp(n-1);
            for(int j=1; j<n; j++)
                temp[j-1]=(words[i][j]-'a')-(words[i][j-1]-'a');
            diff.push_back(temp);
        }
        
        vector<int> same=diff[0], temp=diff[1];
        if(same==temp) {
            for(int i=2; i<diff.size(); i++) {
                if(diff[i]!=same) return words[i];
            }            
        }
        else {
            if(same==diff[2]) return words[1];
            else return words[0];
        }
        return "";
        
    }
};