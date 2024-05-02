class Solution {
    public int findMaxK(int[] nums) {
        HashSet<Integer> s = new HashSet<>();
        int ans=-1;

        for(int num: nums) {
            s.add(num);
            int neg = -1*num;
            if(s.contains(neg))
                ans = Math.max(ans, num<0?neg:num);
        }

        return ans;
    }
}