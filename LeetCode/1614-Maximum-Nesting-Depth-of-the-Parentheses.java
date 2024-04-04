class Solution {
    public int maxDepth(String s) {
        int ans=0, brackets=0;

        for(Character c: s.toCharArray()) {
            if(c=='(') brackets++;
            else if(c==')') brackets --;
            ans=Math.max(ans, brackets);
        }

        return ans;
    }
}