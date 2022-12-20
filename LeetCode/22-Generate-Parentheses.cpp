class Solution {
public:
    vector<string> ans;

    void generate(int open, int close, int n, string result) {
        if(open==n && close==n) ans.push_back(result);

        if(open<n)
            generate(open+1, close, n, result+"(");
        if(close<open)
            generate(open, close+1, n, result+")");
        return;
    }

    vector<string> generateParenthesis(int n) {
        generate(0, 0, n, "");
        return ans;
    }
};