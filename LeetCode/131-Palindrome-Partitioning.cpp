class Solution {
public:
    bool isPali(string& s, int start, int end) {
        while(start<end)
            if(s[start++]!=s[end--]) return false;
        return true;
    }

    void dfs(string&s, int start, vector<string>& currList, vector<vector<string>>& res) {
        int n=s.length();
        if(start>=n) res.push_back(currList);
        for(int end=start; end<n; end++) {
            if(isPali(s, start, end)) {
                currList.push_back(s.substr(start, end-start+1));
                dfs(s, end+1, currList, res);
                currList.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currList;
        dfs(s, 0, currList, res);
        return res;
    }
};