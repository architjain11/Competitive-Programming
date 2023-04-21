class Solution {
public:
    int mySqrt(int x) {
        if(!x) return x;
        int start=1, end=x;
        while(start<=end) {
            int mid=start+(end-start)/2;
            if(mid==x/mid) return mid;
            if(mid>x/mid) end=mid-1;
            else start=mid+1;
        }
        return end;
    }
};