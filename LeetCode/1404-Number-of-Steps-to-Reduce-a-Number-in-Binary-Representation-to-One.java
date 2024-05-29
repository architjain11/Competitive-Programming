class Solution {
    public int numSteps(String s) {
        int l = s.length()-1, carry=0, count=0;
        
        while (l>0) {
            if (Character.getNumericValue(s.charAt(l)) + carry == 0) {
                carry=0;
                count++;
            }
            else if (Character.getNumericValue(s.charAt(l)) + carry == 2) {
                carry=1;
                count++;
            }
            else {
                carry=1;
                count+=2;
            }
            l--;
        }
        
        return carry==1?count+1:count;
    }
}