class Solution {
    public long countSubarrays(int[] nums, int k) {
        int maxEle = Arrays.stream(nums).max().getAsInt(), start = 0, freq = 0;
        long ans = 0;
        
        for(int end = 0; end < nums.length; ++end) {
            if(nums[end] == maxEle)
                freq++;

            while(k == freq) {
                if(nums[start] == maxEle)
                    freq--;
                start++;
            }

            ans += start;
        }

        return ans;
    }
}