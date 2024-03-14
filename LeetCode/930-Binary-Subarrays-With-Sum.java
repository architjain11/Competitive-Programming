class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int total=0, currsum=0;
        Map<Integer, Integer> freq = new HashMap<>();

        for(int num: nums) {
            currsum+=num;
            if(currsum==goal) total++;

            if(freq.containsKey(currsum-goal))
                total+=freq.get(currsum-goal);

            freq.put(currsum, freq.getOrDefault(currsum, 0)+1);
        }

        return total;
    }
}