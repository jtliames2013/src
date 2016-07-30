* Given: An array of strings where L indicates land and W indicates water,
*   and a coordinate marking a starting point in the middle of the ocean.
*
* Challenge: Find and mark the ocean in the map by changing appropriate Ws to Os.
*   An ocean coordinate is defined to be the initial coordinate if a W, and
*   any coordinate directly adjacent to any other ocean coordinate.
*
* void findOcean(String[] map, int row, int column);
*
* String[] map = new String[]{
*  "WWWLLLW",
*  "WWLLLWW",
*  "WLLLLWW"
* };
* printMap(map);
*
* STDOUT:
* WWWLLLW
* WWLLLWW
* WLLLLWW
*
* findOcean(map, 0, 1);
*
* printMap(map);
*
* STDOUT:
* OOOLLLW
* OOLLLWW
* OLLLLWW
*/
先问了iteration的方法比recursion好在哪里，然后我用iteration写了一个DFS，当然还写好了main function，现场跑，有一点点小bug，马上就跑过了。然后面试官问了时间复杂度，不断问我如何优化来减少不必要的backtracking。对这道题而言，我说用BFS可能更快一点，每找到一个点就马上标记为‘O’。面试官还是不满意。又问在BFS的while loop里你还能做什么改进？你已经遍历过这个点了如何避免再次遍历它？额沉默。。。沉默了一会儿他说好了，就酱吧。
怒求RP~同时求问如何进一步优化。

class Solution {
public:
	void findOcean(vector<vector<char> >& grid, int row, int col) {
		int m=grid.size();
		if (m==0) return;
		int n=grid[0].size();
		if (n==0) return;

		if (grid[row][col]=='W') {
			queue<pair<int,int>> q;
			q.push({row, col});
			grid[row][col]='O';
			int delta[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
			while (!q.empty()) {
				pair<int,int> f=q.front();
				q.pop();

				for (int k=0; k<4; k++) {
					int nx=f.first+delta[k][0];
					int ny=f.second+delta[k][1];
					if (nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]=='W') {
						grid[nx][ny]='O';
						q.push({nx,ny});
					}
				}
			}
		}
	}
};

void printGrid(vector<vector<char> >& grid) {
	int m=grid.size();
	int n=grid[0].size();
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}
int main() {
	vector<vector<char> > grid={{'W','W','W','L','L','L','W'},{'W','W','L','L','L','W','W'},{'W','L','L','L','L','W','W'}};
	Solution s;
	s.findOcean(grid, 0, 1);
	printGrid(grid);
	return 0;
}

