class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> arr{0, INT_MIN};
        
        for(int i=0; i<mat.size(); i++) {
            int sum=accumulate(mat[i].begin(), mat[i].end(), 0);
            if(sum>arr[1]) {
                arr[1]=sum;
                arr[0]=i;
            }
        }
        
        return arr;
    }
};