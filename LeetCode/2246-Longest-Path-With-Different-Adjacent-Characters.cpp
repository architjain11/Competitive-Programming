class Solution {
public:
    int longest=1;
    int dfs(vector<vector<int>>& children, int node, string& s) {
        int firstlongest=0, secondlongest=0;
        for(auto& child: children[node]) {
            int longestfromchild=dfs(children, child, s);
            if(s[node]==s[child]) continue;

            if(longestfromchild>firstlongest) {
                secondlongest=firstlongest;
                firstlongest=longestfromchild;
            }
            else if(longestfromchild>secondlongest)
                secondlongest=longestfromchild;
        }
        longest=max(longest, firstlongest+secondlongest+1);
        return firstlongest+1;
    }    

    int longestPath(vector<int>& parent, string s) {
        int n=s.length();
        vector<vector<int>> children(n);
        for(int i=1; i<n; i++)
            children[parent[i]].push_back(i);
        dfs(children, 0, s);
        return longest;
    }
};