class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix==null || matrix.length==0 || matrix[0].length==0)
            return 0;

        int r=matrix.length, c=matrix[0].length;
        int[] heights = new int[c+1];
        int ans=0;

        for(char[] row: matrix) {
            for(int i=0; i<c; ++i) 
                heights[i] = row[i]=='1' ? heights[i]+1 : 0;

            Stack<Integer> stack = new Stack<>();
            for(int i=0; i<heights.length; ++i) {
                while(!stack.isEmpty() && heights[i]<heights[stack.peek()]) {
                    int h=heights[stack.pop()];
                    int w=stack.isEmpty() ? i : i-stack.peek()-1;
                    ans = Math.max(ans, h*w);
                }
                stack.push(i);
            }
        }

        return ans;
    }
}