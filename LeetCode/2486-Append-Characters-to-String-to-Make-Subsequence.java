class Solution {
    public int appendCharacters(String s, String t) {
        int si = 0, ti = 0;
        int sl = s.length(), tl = t.length();
        
        while (si<sl && ti<tl) {
            if (s.charAt(si) == t.charAt(ti))
                ti++;
            si++;
        }
        
        return tl-ti;
        
    }
}