2. 做一个Battle Ship游戏，地图是一个10*10二维数组。在地图上随机位置放3搜船， 长度分别是3、4、5。 实现一个 hit(x, y) 函数， 返回如果hit (x,y)位置会发生什么结果。
结果有3种： HIT 表示打中， MISS表示不中， SUNK 表示船沉（船上所有位置都被击中）。

#define BOARD_SIZE 10

enum Status {
	HIT=0,
	MISS,
	SUNK,
};

class Ship {
public:
	bool isHorizontal;
	int startRow;
	int startCol;
	int length;
	int hitCnt;
	vector<bool> hitStatus;
	Ship(bool h, int r, int c, int l):isHorizontal(h), startRow(r), startCol(c),
	                                  length(l), hitCnt(0)
	{ hitStatus.resize(l, false); }
};

class Solution {
public:
	Solution () {
		ships.push_back(Ship(true, 0, 0, 3));
		ships.push_back(Ship(true, 5, 3, 4));
		ships.push_back(Ship(false, 2, 1, 5));
	}

	Status playHit(int row, int col) {
		Status status=MISS;
		if (row<0 || row>=BOARD_SIZE || col<0 || col>=BOARD_SIZE) return status;

		for (int i=0; i<ships.size(); i++) {
			int startRow=ships[i].startRow;
			int startCol=ships[i].startCol;
			if (ships[i].isHorizontal) {
				if (row==startRow && col>=startCol && col<startCol+ships[i].length) {
					int index=col-startCol;
					if (ships[i].hitStatus[index]==false) {
						ships[i].hitStatus[index]=true;
						ships[i].hitCnt++;
						if (ships[i].hitCnt==ships[i].hitStatus.size()) {
							status=SUNK;
						} else {
							status=HIT;
						}
					}
				}
			} else {
				if (col==startCol && row>=startRow && row<startRow+ships[i].length) {
					int index=row-startRow;
					if (ships[i].hitStatus[index]==false) {
						ships[i].hitStatus[index]=true;
						ships[i].hitCnt++;
						if (ships[i].hitCnt==ships[i].hitStatus.size()) {
							status=SUNK;
						} else {
							status=HIT;
						}
					}
				}
			}
		}

		return status;
	}

private:
	vector<Ship> ships;
};

int main() {
	Solution s;
	Status res;
	res=s.playHit(0,0);
	cout << res << endl;
	res=s.playHit(0,1);
	cout << res << endl;
	res=s.playHit(0,2);
	cout << res << endl;

	res=s.playHit(5,6);
	cout << res << endl;

	res=s.playHit(4,1);
	cout << res << endl;

	res=s.playHit(6,8);
	cout << res << endl;

	return 0;
}

