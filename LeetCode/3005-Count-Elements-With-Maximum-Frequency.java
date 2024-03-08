class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for(int num: nums)
            m.put(num, m.getOrDefault(num, 0)+1);

        int maxfreq=Integer.MIN_VALUE;
        for(int freq: m.values())
            maxfreq = Math.max(maxfreq, freq);

        int ans=0;
        for(int freq: m.values())
            if(freq==maxfreq) ans+=maxfreq;

        return ans;
    }
}