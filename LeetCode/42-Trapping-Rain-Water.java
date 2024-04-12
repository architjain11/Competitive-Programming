class Solution {
    public int trap(int[] height) {
        int i=0, j=height.length-1, left=height[0], right=height[j], water=0;

        while(i<j) {
            if(left<=right) {
                water+=left-height[i];
                ++i;
                left=Math.max(left, height[i]);
            }
            else {
                water+=right-height[j];
                --j;
                right=Math.max(right, height[j]);
            }
        }

        return water;
    }
}