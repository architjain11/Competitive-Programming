class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> empty = {};
        vector<vector<string>> ans;
        map<string, int> m;
        int i=0;
        
        for(auto str : strs) {
            string sortedWord = str;
            sort(sortedWord.begin(), sortedWord.end());
            if(m.count(sortedWord)) {
                ans[m[sortedWord]].push_back(str);
            }
            else{
                m[sortedWord] = i;
                ans.push_back(empty);
                ans[m[sortedWord]].push_back(str);
                i++;
            }
        }
        return ans;
    }
};