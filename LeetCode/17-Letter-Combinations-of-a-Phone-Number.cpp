class Solution {
public:
    vector<string> ans;

    void solve(string digits, int i, string curr, unordered_map<char, string>& mp) {
        if(curr.length()==digits.length()) {
            ans.push_back(curr);
            return;
        }

        for(auto c: mp[digits[i]])
            solve(digits, i+1, curr+c, mp);
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        if(digits.length()>0)
            solve(digits, 0, "", mp);
        return ans;
    }
};