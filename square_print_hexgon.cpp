如图这个平面蜂窝结构，每一个cell是正六边形，每个cell都有六个相邻的cells。
整个蜂窝的高和宽 （cell数）是可以任意输入的，注意相邻的列都是上下错开的。设计class ＋ function， 给定高和宽，再给定一个数字，顺时针打印出与数字对应的cell相邻的六个cell里面的数字。比如图例，在高和宽input 为 3和6，输入index为4的情况，按顺序打印出3，7，8，5，2，1.  如果赶上边缘上的cell（没有6个相邻的cells），空缺的位置要打印“－1”.. 
数据结构自己设计，数据自己初始化，就连运行test那两行代码也要自己写。总之所有东西都是自己写。

这个题现场写的时候各种index很凌乱，容易出错。lz就是最后程序有个bug，运行结果不对，面试官说他大体懂我的意思，解法是对的，和我一起debug了一会儿没找出来bug。时间到了然后就开始Q&A了。（面试结束后lz又找了15分钟才把bug找出来了。。。） 题目做过一遍回头想就不算难了，就是需要细心和镇静，而且现场短时间内想清楚还要把代码写出来还要bug free，就得下功夫了。Square好像大部分时候看面经没用，看看感受一下难度就好了。

__     __     __      __   
/0 \__/6 \_/12\__/   \__
\__/3 \_/9 \__/15\__/  
/1  \_/7\__/13\__/   \__
\__/4 \_/10\__/16\__/  . 
/2 \__/8 \__/14\__/  \__
\__/5 \__/11\__/17\__/  
/   \_ /    \__/    \__/  \__. 


class Solution {
public:
	vector<int> printHexgonCircle(vector<vector<int> > board, int row, int col) {
		vector<int> res;
		int deltaOdd[6][2]={{-1,0},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
		int deltaEven[6][2]={{-1,0},{-1,1},{0,1},{1,0},{0,-1},{-1,-1}};

		int m=board.size();
		int n=board[0].size();

		for (int k=0; k<6; k++) {
			int nr=row+(col%2==0?deltaEven[k][0]:deltaOdd[k][0]);
			int nc=col+(col%2==0?deltaEven[k][1]:deltaOdd[k][1]);

			if (nr>=0 && nr<m && nc>=0 && nc<n) {
				res.push_back(board[nr][nc]);
			} else {
				res.push_back(-1);
			}
		}

		return res;
	}
};

int main() {
	Solution s;
	vector<vector<int> > board={{0,3,6,9,12,15},
								{1,4,7,10,13,16},
								{2,5,8,11,14,17}};
	//vector<int> res=s.printHexgonCircle(board, 1, 1);
	vector<int> res=s.printHexgonCircle(board, 2, 3);
	for (int i=0; i<res.size(); i++) cout << res[i] << " ";
	cout << endl;
	return 0;
}

