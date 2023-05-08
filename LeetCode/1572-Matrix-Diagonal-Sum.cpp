class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(), sum=0;
        for(int i=0; i<n; ++i) sum+=mat[i][i];
        for(int i=n-1; i>=0; --i) sum+=mat[n-i-1][i];

        return n%2!=0?sum-mat[n/2][n/2]:sum;
    }
};