public class Solution {
    public int longestPalindrome(String s) {
        Set<Character> charSet = new HashSet<>();
        int length = 0;

        for (char c: s.toCharArray()) {
            if (charSet.contains(c)) {
                charSet.remove(c);
                length += 2;
            } 
            else
                charSet.add(c);
        }

        return length + (charSet.isEmpty() ? 0 : 1);
    }
}
