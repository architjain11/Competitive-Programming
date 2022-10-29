class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto query: queries) {
            bool found=false;
            for(auto dict: dictionary) {
                if(found==true) break;
                if(query.length()!=dict.length()) continue;
                else {
                    int change=0;
                    for(int i=0; i<query.length(); i++) {
                        if(query[i]!=dict[i]) change++;
                    }
                    if(change<=2) {
                        ans.push_back(query); 
                        found=true;
                    }
                        
                }
            }
        }
        return ans;
    }
};