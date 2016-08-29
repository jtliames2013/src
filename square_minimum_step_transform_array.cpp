(3) 一个 2 ＊4 的数组不重复包含1-8这些整数，有3种操作。

a) 上下两个row交换
b) 所有元素向右shift一个位置. 
c) 中间4个元素，顺时针旋转90度
现在随便给一个这样的数组，最小复员到1234，5678的步骤。

同样bfs，只是要在为2*4 array写个hash function。

class Grid {
public:
	Grid(vector<vector<int> > data) {
		this->data=data;
		this->hash=getHash();
	}

	size_t getHash() {
		string str;
		for (int i=0; i<2; i++) {
			for (int j=0; j<4; j++) {
				str+=to_string(data[i][j]);
			}
		}
		return std::hash<std::string>{}(str);
	}
	void transform1() {
		for (int i=0; i<4; i++) {
			swap(data[0][i], data[1][i]);
		}
		this->hash=getHash();
	}

	void transform2() {
		for (int i=0; i<2; i++) {
			int tmp=data[i][3];
			for (int j=3; j>0; j--) {
				data[i][j]=data[i][j-1];
			}
			data[i][0]=tmp;
		}
		this->hash=getHash();
	}

	void transform3() {
		int tmp=data[0][1];
		data[0][1]=data[1][1];
		data[1][1]=data[1][2];
		data[1][2]=data[0][2];
		data[0][2]=tmp;
		this->hash=getHash();
	}

	Grid& operator=(const Grid& g) {
		this->data=g.data;
		this->hash=g.hash;
		return *this;
	}

	bool operator==(const Grid& g) {
		for (int i=0; i<2; i++) {
			for (int j=0; j<4; j++) {
				if (this->data[i][j]!=g.data[i][j]) return false;
			}
		}
		return true;
	}

	vector<vector<int> > data;
	size_t hash;
};

class Solution {
public:
	int getMinimumDistance(Grid start, Grid end) {
		if (start==end) return 0;
		int dist=1;
		queue<Grid> q;
		set<int> visited;
		q.push(start);
		visited.insert(start.hash);
		int currLevel=1;
		int nextLevel=0;

		while (!q.empty()) {
			Grid f=q.front();
			q.pop();
			currLevel--;

			for (int i=0; i<3; i++) {
				Grid neighbor=f;
				if (i==0) {
					neighbor.transform1();
				} else if (i==1) {
					neighbor.transform2();
				} else {
					neighbor.transform3();
				}
				if (neighbor==end) return dist+1;
				if (visited.find(neighbor.hash)==visited.end()) {
					q.push(neighbor);
					visited.insert(neighbor.hash);
					nextLevel++;
				}
			}

			if (currLevel==0) {
				currLevel=nextLevel;
				nextLevel=0;
				dist++;
			}
		}

		return -1;
	}
};

int main() {
	Solution s;
	Grid orig({{1,2,3,4},{5,6,7,8}});
	Grid g({{2,3,4,1},{6,7,8,5}});
	int res=s.getMinimumDistance(g, orig);
	cout << res << endl;
	return 0;
}

