class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> s = new Stack<>();

        for(char dig: num.toCharArray()) {
            while(!s.isEmpty() && k>0 && s.peek()>dig) {
                s.pop();
                k--;
            }
            s.push(dig);
        }

        while(k>0 && !s.isEmpty()) {
            s.pop();
            k--;
        }

        StringBuilder a = new StringBuilder();

        while(!s.isEmpty())
            a.append(s.pop());

        a.reverse();
        while(a.length()>0 && a.charAt(0)=='0')
            a.deleteCharAt(0);

        return a.length()>0?a.toString():"0";
    }
}