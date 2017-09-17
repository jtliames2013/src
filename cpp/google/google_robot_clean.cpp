Given a robot cleaner in a room modeled as a grid. Each cell in the grid can be empty or blocked. The robot cleaner can move forward, turn left or turn right. When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.


The control API:

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean Move();

  // Robot will stay on the same cell after calling Turn*. k indicates how
  // many turns to perform.
  void TurnLeft(int k);
  void TurnRight(int k);

  // Clean the current cell.
  void Clean();

  boolean Move(Direction d);
}

sample input
++++++++++
+........+
+...^....+
+.+......+
++++.+++++
+.....+
+++++++


要求用给定的API打扫完所有empty格子。

楼主一开始想用bfs做，后来发现我连robot的位置都不知道。。

于是面试官简化
简化1：robot自己可以知道自己当前的位置。就是两个新API：robot.x(), robot.y()

楼主到这里还是一脸懵逼，于是面试官又提示：你怎样让robot从一个点走到格子里的另一个点。

typedef int Direction;

class Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  bool Move();

  // Robot will stay on the same cell after calling Turn*. k indicates how
  // many turns to perform.
  void TurnLeft(int k);
  void TurnRight(int k);

  // Clean the current cell.
  void Clean();

  bool Move(Direction d);

  int getDirection();

  void setDirection(int d);
};

class Solution {
public:
	unsigned long long key(int x, int y) {
		return (unsigned long long) x<<32 | (unsigned int) y;
	}

	void dfs(unordered_map<int, int>& mp, Robot r, int row, int col) {
		mp[key(row, col)]=1;
		r.Clean();
		int dir=r.getDirection();
		for (int k=0; k<4; k++) {
			int d=(dir+k)%4;
			r.TurnRight(k);
			int nr=row+dirs[d][0];
			int nc=col+dirs[d][1];
			if (r.Move() && mp.find(key(nr,nc))==mp.end()) {
				r.Move(d);
				dfs(mp, r, nr, nc);
			}
		}

		mp[key(row, col)]=2;
		r.TurnRight(2);
		r.Move(dir+2);
	}
	void robotClean(Robot r) {
		unordered_map<unsigned long long, int> mp;
		dfs(mp, r, 0, 0);
	}
private:
	int dirs[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

