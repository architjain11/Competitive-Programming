class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean one = false;

        for(int i=0; i<n; ++i) {
            if(nums[i]==1)
                one = true;
            if(nums[i]<=0 || nums[i]>n)
                nums[i] = 1;
        }

        if(!one) return 1;

        for(int i=0; i<n; ++i) {
            int val = Math.abs(nums[i]);
            if(val==n)
                nums[0] = -Math.abs(nums[0]);
            else
                nums[val] = -Math.abs(nums[val]);
        }

        for(int i=1; i<n; ++i)
            if(nums[i]>0)
                return i;

        if(nums[0]>0)
            return n;

        return n+1;
    }
}