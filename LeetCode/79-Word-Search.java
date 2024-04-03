class Solution {
    public boolean solve(char[][] board, String word, boolean[][] visited, int i, int j, int curr) {
        if(curr==word.length())
            return true;
        if(i<0 || i>=board.length || j<0 || j>=board[0].length || board[i][j]!=word.charAt(curr) || visited[i][j])
            return false;
        
        visited[i][j]=true;
        if (solve(board, word, visited, i+1, j, curr+1) ||
            solve(board, word, visited, i-1, j, curr+1) ||
            solve(board, word, visited, i, j+1, curr+1) ||
            solve(board, word, visited, i, j-1, curr+1))
            return true;

        visited[i][j]=false;
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int m=board.length, n=board[0].length;
        boolean[][] visited=new boolean[m][n];
        boolean ans=false;

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(board[i][j]==word.charAt(0)) {
                    ans = solve(board, word, visited, i, j, 0);
                    if(ans) return true;
                }
            }
        }

        return false;
    }
}