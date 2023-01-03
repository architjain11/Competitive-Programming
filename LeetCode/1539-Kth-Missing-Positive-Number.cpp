class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num=1;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]!=num) {
                k--;
                i--;
            }
            if(k==0) break;
            num++;
        }
        return k==0?num:num+k-1;
    }
};