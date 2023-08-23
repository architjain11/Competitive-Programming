class Solution {
public:
    int helper(vector<vector<char>>& matrix, int r, int c, map<vector<int>, int>& cache) {
        int rows=matrix.size(), cols=matrix[0].size();
        if(r>=rows || c>=cols) return 0;
        if(cache.count({r, c})) return cache[{r, c}];

        int down=helper(matrix, r+1, c, cache),
            right=helper(matrix, r, c+1, cache),
            diagonal=helper(matrix, r+1, c+1, cache);

        cache[{r, c}]=0;
        if(matrix[r][c]=='1')
            cache[{r, c}]=1+min(down, min(right, diagonal));
        return cache[{r, c}];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        map<vector<int>, int> cache;
        helper(matrix, 0, 0, cache);
        auto max_value = max_element(cache.begin(), cache.end(), [](const auto &p1, const auto &p2) {
            return p1.second < p2.second;
        });
        return pow(max_value->second, 2);
    }
};