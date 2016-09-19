public class Solution {
    class Pos {
        int row;
        int col;
        Pos(int r, int c) {
            row=r;
            col=c;
        }
    }
    void bfs(char[][] grid, boolean[][] visited, int row, int col, int m, int n) {
        ArrayDeque<Pos> queue=new ArrayDeque<>();
        queue.offer(new Pos(row,col));
        visited[row][col]=true;
        int[][] delta=new int[][] {{-1,0},{1,0},{0,-1},{0,1}};
        
        while (!queue.isEmpty()) {
            Pos p=queue.poll();
            
            for (int k=0; k<4; k++) {
                int nr=p.row+delta[k][0];
                int nc=p.col+delta[k][1];
                if (nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1'&&visited[nr][nc]==false) {
                    queue.offer(new Pos(nr,nc));
                    visited[nr][nc]=true;
                }
            }
        }
     }
    
    public int numIslands(char[][] grid) {
        int m=grid.length;
        if (m==0) return 0;
        int n=grid[0].length;
        if (n==0) return 0;
        boolean[][] visited=new boolean[m][n];
        
        int count=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='1' && visited[i][j]==false) {
                    bfs(grid, visited, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
}

2.
public class Solution {
    class Pos {
        int row;
        int col;
        Pos(int r, int c) {
            row=r;
            col=c;
        }
    }
    void bfs(char[][] grid, int row, int col, int m, int n) {
        ArrayDeque<Pos> queue=new ArrayDeque<>();
        queue.offer(new Pos(row,col));
        grid[row][col]='2';
        int[][] delta=new int[][] {{-1,0},{1,0},{0,-1},{0,1}};
        
        while (!queue.isEmpty()) {
            Pos p=queue.poll();
            
            for (int k=0; k<4; k++) {
                int nr=p.row+delta[k][0];
                int nc=p.col+delta[k][1];
                if (nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1') {
                    queue.offer(new Pos(nr,nc));
                    grid[nr][nc]='2';
                }
            }
        }
     }
    
    public int numIslands(char[][] grid) {
        int m=grid.length;
        if (m==0) return 0;
        int n=grid[0].length;
        if (n==0) return 0;
        
        int count=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='1') {
                    bfs(grid, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
}
