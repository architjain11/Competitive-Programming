class Solution {
    public int minimumLength(String s) {
        int l=0, r=s.length()-1;

        while(l<r && s.charAt(l)==s.charAt(r)) {
            char tmp=s.charAt(l);
            while(l<=r && s.charAt(l)==tmp) l++;
            while(r>l && s.charAt(r)==tmp) r--;
        }

        return r-l+1;
    }
}