class Solution {
    public int pivotInteger(int n) {
        int l=1, r=n, total=n*(n+1)/2;

        while(l<r) {
            int mid = (l+r)/2;

            if(mid*mid<total) l=mid+1;
            else r=mid;
        }

        if(l*l==total) return l;
        else return -1;
    }
}