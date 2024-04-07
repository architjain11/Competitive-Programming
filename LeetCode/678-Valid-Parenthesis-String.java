class Solution {
    public boolean checkValidString(String s) {
        int minimum=0, maximum=0;

        for(char c: s.toCharArray()) {
            if(c=='(') {
                minimum++;
                maximum++;
            }
            else if(c==')') {
                minimum--;
                maximum--;
            }
            else {
                minimum--;
                maximum++;
            }
            if(maximum<0) return false;
            if(minimum<0) minimum=0;
        }

        return minimum==0;
    }
}