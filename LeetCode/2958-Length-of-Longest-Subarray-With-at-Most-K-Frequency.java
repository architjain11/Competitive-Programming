class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int ans=0;
        Map<Integer, Integer> freq=new HashMap();

        for(int start=-1, end=0; end<nums.length; ++end) {
            freq.put(nums[end], freq.getOrDefault(nums[end], 0)+1);
            while(freq.get(nums[end])>k) {
                start++;
                freq.put(nums[start], freq.get(nums[start])-1);
            }
            ans=Math.max(ans, end-start);
        }

        return ans;
    }
}