class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto row: matrix) {
            int low=0, high=row.size()-1, mid;
            
            if(target>row[high])
                continue;
            
            while(low<=high) {
                mid = (low+high)/2;
                if(target == row[mid])
                    return true;
                else if(target>row[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return false;
    }
};