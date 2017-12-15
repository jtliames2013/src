paint a board，给定一个board，即matrix，里面所有元素最开始都为O，要求从点(x0, y0)划出一条线到(x1, y1)，这条线上的点为“\”
如果是刚好一条直线，比如(0, 0) (3, 3)这种，直接画一条直线就好
但是复杂的地方是，因为是matrix，没法画出来一部分，比如对于(0, 0) (4, 7)，这个不是一条“完美的45度直线”，所有有些cell会出现“扭曲”的现象，比如从(0,0) 到 (3, 2)，画出来的线是这样子的
\OOOO
O\OOO
O\OOO
OO\OO
我的解法就是，现根据输入的两个点的坐标计算出来线性方程 y = kx + b中的斜率和截距b
然后从初始点每次移动x的时候（即x=x+1），根据这个直线方程计算出对应的y，是一个float，然后round it，算出近似值，就是对应的y坐标
比如x=3，y算出来=9.2，那么下一次就需要将(3, 9)这个cell变为X，而不是(3, 10)
还有一个假设就是，如果x坐标挪动的距离比y坐标要大，此时每次x+1求得y的值；否则y比x大，需要每次y+1然后求的对应的x的值
比如(0, 0) (4, 7) y轴要挪动7次，x轴挪动4次，那么我们每次y+1，算出来的rounded x就是对应的cell index
蛮复杂的一道题目，edge case比较多

paint program, 先是给一个board，然后让画一条线，可以是斜线，斜线比较麻烦

class Solution {
public:
	Solution(int m, int n) {
		this->m=m;
		this->n=n;
	}

	void printLine(int row, int col) {
		vector<vector<char>> board(m, vector<char>(n, '0'));
		if (row==0) {
			for (int i=0; i<=col; i++) board[row][i]='-';
		} else if (col==0) {
			for (int i=0; i<=row; i++) board[i][col]='|';
		} else {
			double len=col, div=row;
			for (int i=0; i<=row; i++) {
				int j=i*len/div;
				board[i][j]='\\';
			}
		}

		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
private:
	int m;
	int n;
};

int main() {
	Solution s(5,5);
	s.printLine(4,4);
	s.printLine(4,0);
	s.printLine(4,2);
	s.printLine(2,4);
}

