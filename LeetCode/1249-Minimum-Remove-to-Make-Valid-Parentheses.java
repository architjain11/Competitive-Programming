class Solution {
    public String minRemoveToMakeValid(String s) {
        int l = 0, r = 0;
        Stack<Character> st = new Stack<>();

        for(int i=0; i<s.length(); ++i) {
            char curr = s.charAt(i);
            if(curr=='(') l++;
            if(curr==')') r++;

            if(r>l) {
                r--;
                continue;
            }
            else st.push(curr);
        }

        StringBuilder ans = new StringBuilder();
        while(!st.isEmpty()) {
            char curr = st.pop();
            if(l>r && curr=='(') l--;
            else ans.append(curr);
        }

        return ans.reverse().toString();
    }
}