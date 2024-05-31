class Solution {
    public int[] singleNumber(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        
        for (int n: nums)
            freq.put(n, freq.getOrDefault(n, 0) + 1);

        int[] ans = new int[2];
        int index = 0;
        for (Map.Entry<Integer, Integer> entry: freq.entrySet()) {
            if (entry.getValue() == 1) {
                ans[index++] = entry.getKey();
                if (index == 2)
                    break;
            }
        }

        return ans;
    }
}