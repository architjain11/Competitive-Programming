class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int n1=nums1.length, n2=nums2.length;
        
        for(int i=0, j=0; i<n1 && j<n2; i++, j++) {
            int a=nums1[i], b=nums2[j];
            if(a==b) return a;
            if(a<b) j--;
            else i--;
        }
        
        return -1;
    }
}