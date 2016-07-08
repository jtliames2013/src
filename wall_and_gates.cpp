286. Walls and Gates
 You are given a m x n 2D grid initialized with these three possible values.

    -1 - A wall or an obstacle.
    0 - A gate.
    INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

NOTE: Use BFS. update when level is less. check 4 neighbors (not else if)

  class Solution {
  public:
	  struct Element {
		  int row;
		  int col;
		  int level;
		  Element(int r, int c, int l): row(r), col(c), level(l) {}
	  };
	  void bfs(vector<vector<int> >& rooms, int i, int j) {
		  int level=0;
		  queue<Element> q;
		  int row=rooms.size();
		  int col=rooms[0].size();

		  Element e(i, j, 0);
		  q.push(e);

		  while (!q.empty()) {
			  Element elem=q.front();
			  q.pop();
			  if (elem.row>0 && rooms[elem.row-1][elem.col]!=-1) {
				  if (rooms[elem.row-1][elem.col]>elem.level+1) {
					  rooms[elem.row-1][elem.col]=elem.level+1;
					  q.push(Element(elem.row-1, elem.col, elem.level+1));
				  }
			  }
			  if (elem.row<row-1 && rooms[elem.row+1][elem.col]!=-1) {
				  if (rooms[elem.row+1][elem.col]>elem.level+1) {
					  rooms[elem.row+1][elem.col]=elem.level+1;
					  q.push(Element(elem.row+1, elem.col, elem.level+1));
				  }
			  }
			  if (elem.col>0 && rooms[elem.row][elem.col-1]!=-1) {
				  if (rooms[elem.row][elem.col-1]>elem.level+1) {
					  rooms[elem.row][elem.col-1]=elem.level+1;
					  q.push(Element(elem.row, elem.col-1, elem.level+1));
				  }
			  }
			  if (elem.col<col-1 && rooms[elem.row][elem.col+1]!=-1) {
				  if (rooms[elem.row][elem.col+1]>elem.level+1) {
					  rooms[elem.row][elem.col+1]=elem.level+1;
					  q.push(Element(elem.row, elem.col+1, elem.level+1));
				  }
			  }
		  }
	  }

      void wallsAndGates(vector<vector<int>>& rooms) {
    	  int row=rooms.size();
    	  if (row==0) return;
    	  int col=rooms[0].size();
    	  if (col==0) return;

    	  for (int i=0; i<row; i++) {
    		  for (int j=0; j<col; j++) {
    			  if (rooms[i][j]==0) {
    				  bfs(rooms, i, j);
    			  }
    		  }
    	  }
      }
  };

2. DFS
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int row, int col, int m, int n, int level) {
        int delta[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for (int i=0; i<4; i++) {
            int nx=row+delta[i][0];
            int ny=col+delta[i][1];
            
            if (nx>=0 && nx<m && ny>=0 && ny<n && rooms[nx][ny]!=-1 && rooms[nx][ny]!=0) {
                level++;
                if (rooms[nx][ny]>level) {
                    rooms[nx][ny]=level;
                    dfs(rooms, nx, ny, m, n, level);
                }
                level--;
            }
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        if (m==0) return;
        int n=rooms[0].size();
        if (n==0) return;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (rooms[i][j]==0) {
                    dfs(rooms, i, j, m, n, 0);
                }
            }
        }
    }
};


