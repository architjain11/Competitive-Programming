class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int h=matrix.size(), l=matrix[0].size();
        for(int j=0; j<l; j++) {
            int i=0, k=j;
            int val=matrix[i][j];
            while(i<h && k<l) {
                if(matrix[i][k]!=val) return false;
                i++; k++;  
            }
        }
        for(int i=1; i<h; i++) {
            int j=0, k=i;
            int val=matrix[i][j];
            while(j<l && k<h) {
                if(matrix[k][j]!=val) return false;
                j++; k++;
            }
        }
        return true;
    }
};