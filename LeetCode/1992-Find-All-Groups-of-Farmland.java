class Solution {
    int r2, c2;

    private boolean within(int x, int y, int n, int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }

    private void dfs(int[][] land, boolean[][] visited, int x, int y) {
        visited[x][y] = true;
        r2 = Math.max(r2, x);
        c2 = Math.max(c2, y);
        int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        for(int[] dir: dirs) {
            int newX = x + dir[0], newY = y + dir[1];

            if (within(newX, newY, land.length, land[0].length) && !visited[newX][newY] && land[newX][newY] == 1)
                dfs(land, visited, newX, newY);
        }
    }

    public int[][] findFarmland(int[][] land) {
        int n = land.length, m = land[0].length;
        boolean[][] visited = new boolean[n][m];
        List<int[]> ans = new ArrayList<>();

        for(int r1=0; r1<n; ++r1) {
            for(int c1=0; c1<m; ++c1) {
                if(land[r1][c1]==1 && !visited[r1][c1]) {
                    r2=0; c2=0;
                    dfs(land, visited, r1, c1);
                    int[] arr = new int[] {r1, c1, r2, c2};
                    ans.add(arr);
                }
            }
        }

        return ans.stream().toArray(int[][]::new);
    }
}