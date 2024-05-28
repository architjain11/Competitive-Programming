class Solution {
    public int equalSubstring(String s, String t, int maxCost) {        
        int maxLen = 0, start = 0, curr = 0;
        
        for (int i=0; i<s.length(); ++i) {
            curr += Math.abs(s.charAt(i) - t.charAt(i));
            while (curr > maxCost) {
                curr -= Math.abs(s.charAt(start) - t.charAt(start));
                start++;
            }   
            maxLen = Math.max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
}