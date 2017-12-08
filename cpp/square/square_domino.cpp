1. 第一轮面试是个 Dominoes, 先写类表示Dominoes和bags, 比如说  [1,2] 表示这个dominoes 上面是骰子1 下面是骰子2, 然后找出是否存在一个路径[[1,2], [2,3],[3,4]]
   我想了下打算用hash做,这样不用每次都搜索, 结果被面试官否决了, 里有是 dominoes的size是k, 即使搜索的O(kn)也是O(n),让我直接搜.
   然后就写了个算法, 测试通过.
   Follow up 是如果骰子上下部分咋办.上下部分就搜索的时候俩面都看一下.
   Follow up 是是否存在一个环, 比如存在骰子 [0,1], [1.2], [2,3] [3,0] 就算一个环. 聊了一下求环的算法, 用DFS写,看topping是否被访问过, 如果被访问过就是环.. 
   Follow up 是如果骰子的上下不分, 比如 [0,1] [2,1] [2,3] [3,0] 也算一个环, 注意到这个和上面那个的区别是把 [1,2] 换成了[2,1].
   打算改我的DFS算法,确实不好写, 最后面试官给了个提示,可以每次遍历的时候,遍历当前的这个dominoes翻过来(就是把top和bottom颠倒一下), 然后就写出来了,注意DFS遍历完以后要把元素翻回去.不然会影响结果.
   第一面觉得还不错, 虽然代码过程中有一些bug,最后都完成了,也都过了测试.

   我在面试第一面的时候, 听到旁边的小哥问那个 square 落下来那题, 我面试前在家还写过这题, 哎!心都碎了,运气不好,没摊上我.

收到HR邮件邀请面试，然后基本在没有准备的状态下裸面了Square。妥妥的跪了，觉得他们家的题设计的很好，发出来回馈社会。1. Domino牌， 牌上有两个数，从范围0-MAX (MAX是预先定义好的常数)， 两个数字可以相等，没有顺序。
        - 如何定义这个Domino class. 
        - 如何定义一个包含任意数量的 Domino object的DominoBag class
        - 如何检测一个DominoBag 里面有没有一条从x到y的sequence， sequence指 1|3 --> 3|5 --> 5|7 这种，表示从3到7的sequence
        - 如何检测一个DominoBag 中有没有一条回路，比如 1|3 --> 3|5 --> 5|7 --> 7|1

貌似是板上有的Domino, 基本就是几个小题分别是实现domino的类，一些简单的基本功能，最后就是给一个大题，就是给了一袋子domino然后判定里面有没有回路的存在。Domino分top的数字和bottom的数字，比如有domino  1|4， 4|3， 3|1 这样就是一个回路。

这个我当时拿DFS写出来的，我跟面试官说可以拿拓扑排序来写，面试官可能感觉自己不是很熟就继续让我用DFS写了。

struct Domino {
	int front;
	int back;
	Domino(int f, int b):front(f), back(b) {}
};

class Compare{
public:
	bool operator()(Domino a, Domino b) {
		return a.front<b.front || a.back<b.back;
	}
};

class Solution {
public:
	Solution(vector<Domino>& dominoes) {
		for (auto d:dominoes) {
			graph[d.front].insert(d);
		}
	}

	bool existPath(int start, int end) {
		stack<int> stk;
		set<int> visited;
		stk.push(start);
		visited.insert(start);

		while (!stk.empty()) {
			int t=stk.top();
			stk.pop();

			for (auto neighbor:graph[t]) {
				if (neighbor.back==end) return true;
				if (visited.find(neighbor.back)==visited.end()) {
					stk.push(neighbor.back);
					visited.insert(neighbor.back);
				}
			}
		}

		return false;
	}

	bool existCycle() {
		for (auto vertex:graph) {
			set<int> visited;
			visited.insert(vertex.first);
			stack<int> stk;
			stk.push(vertex.first);

			while (!stk.empty()) {
				int t=stk.top();
				stk.pop();

				for (auto neighbor:graph[t]) {
					if (neighbor.back==vertex.first) return true;
					if (visited.find(neighbor.back)==visited.end()) {
						stk.push(neighbor.back);
						visited.insert(neighbor.back);
					}
				}
			}
		}
		return false;
	}

private:
	map<int, set<Domino, Compare> > graph;
};

// no difference between front and back
class Solution2 {
public:
	Solution2(vector<Domino>& dominoes) {
		for (auto d:dominoes) {
			graph[d.front].insert(d);
			graph[d.back].insert(Domino(d.back, d.front));
		}
	}

	bool existPath(int start, int end) {
		stack<int> stk;
		set<int> visited;
		stk.push(start);
		visited.insert(start);

		while (!stk.empty()) {
			int t=stk.top();
			stk.pop();

			for (auto neighbor:graph[t]) {
				if (neighbor.back==end) return true;
				if (visited.find(neighbor.back)==visited.end()) {
					stk.push(neighbor.back);
					visited.insert(neighbor.back);
				}
			}
		}

		return false;
	}

	bool existCycle() {
		for (auto vertex:graph) {
			set<int> visited;
			visited.insert(vertex.first);
			stack<int> stk;
			stk.push(vertex.first);

			while (!stk.empty()) {
				int t=stk.top();
				stk.pop();

				for (auto neighbor:graph[t]) {
					if (neighbor.back==vertex.first) return true;
					if (visited.find(neighbor.back)==visited.end()) {
						stk.push(neighbor.back);
						visited.insert(neighbor.back);
					}
				}
			}
		}
		return false;
	}

private:
	map<int, set<Domino, Compare> > graph;
};

// No graph
class Solution3 {
public:
	bool existPath(vector<Domino>& dominoes, int start, int end) {
		int n=dominoes.size();
		if (n==0) return false;
		vector<bool> visited(n, false);
		return existPath(dominoes, start, end, visited);
	}

	bool existPath(vector<Domino>& dominoes, int start, int end, vector<bool> &visited) {
		for (int i=0; i<dominoes.size(); i++) {
			if (visited[i]==false) {
				if (dominoes[i].front==start) {
					visited[i]=true;
					if (dominoes[i].back==end) return true;
					else {
						if (existPath(dominoes, dominoes[i].back, end, visited)) return true;
					}
					visited[i]=false;
				}
			}
		}
		return false;
	}

	bool existCycle(vector<Domino>& dominoes) {
		int n=dominoes.size();
		if (n==0) return false;
		for (int i=0; i<dominoes.size(); i++) {
			vector<bool> visited(n, false);
			visited[i]=true;
			if (existCycle(dominoes, dominoes[i].front, dominoes[i].back, visited)) return true;
		}
		return false;
	}

	bool existCycle(vector<Domino>& dominoes, int init, int start, vector<bool>& visited) {
		for (int i=0; i<dominoes.size(); i++) {
			if (visited[i]==false) {
				if (dominoes[i].front==start) {
					visited[i]=true;
					if (dominoes[i].back==init) return true;
					else {
						if (existCycle(dominoes, init, dominoes[i].back, visited)) return true;
					}
					visited[i]=false;
				}
			}
		}
		return false;
	}
};

// no difference between front and back
class Solution4 {
public:
	bool existPath(vector<Domino>& dominoes, int start, int end) {
		int n=dominoes.size();
		if (n==0) return false;
		vector<bool> visited(n, false);
		return existPath(dominoes, start, end, visited);
	}

	bool existPath(vector<Domino>& dominoes, int start, int end, vector<bool> &visited) {
		for (int i=0; i<dominoes.size(); i++) {
			if (visited[i]==false) {
				if (dominoes[i].front==start || dominoes[i].back==start) {
					bool frontMatch=(dominoes[i].front==start);
					visited[i]=true;
					if ((frontMatch && dominoes[i].back==end) ||
						 (!frontMatch && dominoes[i].front==end)) return true;
					else {
						if (existPath(dominoes, frontMatch?dominoes[i].back:dominoes[i].front, end, visited)) return true;
					}
					visited[i]=false;
				}
			}
		}
		return false;
	}

	bool existCycle(vector<Domino>& dominoes) {
		int n=dominoes.size();
		if (n==0) return false;
		for (int i=0; i<dominoes.size(); i++) {
			vector<bool> visited(n, false);
			visited[i]=true;
			if (existCycle(dominoes, dominoes[i].front, dominoes[i].back, visited)) return true;
			if (existCycle(dominoes, dominoes[i].back, dominoes[i].front, visited)) return true;
		}
		return false;
	}

	bool existCycle(vector<Domino>& dominoes, int init, int start, vector<bool>& visited) {
		for (int i=0; i<dominoes.size(); i++) {
			if (visited[i]==false) {
				if (dominoes[i].front==start || dominoes[i].back==start) {
					visited[i]=true;
					bool frontMatch=(dominoes[i].front==start);
					if ((frontMatch && dominoes[i].back==init) ||
						(!frontMatch && dominoes[i].front==init)) return true;
					else {
						if (existCycle(dominoes, init, frontMatch?dominoes[i].back:dominoes[i].front, visited)) return true;
					}
					visited[i]=false;
				}
			}
		}
		return false;
	}
};

//  recursive on detecting cycle with graph
class Solution5 {
public:
	Solution5(vector<Domino>& dominoes) {
		for (auto d:dominoes) {
			graph[d.front].insert(d);
		}
	}

	bool existPath(int start, int end) {
		stack<int> stk;
		set<int> visited;
		stk.push(start);
		visited.insert(start);

		while (!stk.empty()) {
			int t=stk.top();
			stk.pop();

			for (auto neighbor:graph[t]) {
				if (neighbor.back==end) return true;
				if (visited.find(neighbor.back)==visited.end()) {
					stk.push(neighbor.back);
					visited.insert(neighbor.back);
				}
			}
		}

		return false;
	}

	bool existCycle(int vertex, set<int>& visited, set<int>& inPath) {
		visited.insert(vertex);
		inPath.insert(vertex);
		for (auto neighbor:graph[vertex]) {
			if (inPath.find(neighbor.back)!=inPath.end()) return true;
			if (visited.find(neighbor.back)==visited.end()) {
				if (existCycle(neighbor.back, visited, inPath)) return true;
			}
		}
		inPath.erase(vertex);
		return false;
	}

	bool existCycle() {
		set<int> visited;
		set<int> inPath;
		for (auto vertex:graph) {
			if (visited.find(vertex.first)==visited.end()) {
				visited.insert(vertex.first);
				if (existCycle(vertex.first, visited, inPath)) return true;
			}
		}
		return false;
	}

private:
	map<int, set<Domino, Compare> > graph;
};

int main() {
	//vector<Domino> dominoes={Domino(1,2), Domino(2,3), Domino(3,4), Domino(4,1)};
	vector<Domino> dominoes={Domino(1,2), Domino(2,3), Domino(3,4), Domino(4,2)};
	Solution s(dominoes);
	bool res=s.existPath(1, 4);
	cout << res << endl;
	bool cycle=s.existCycle();
	cout << cycle << endl;

	vector<Domino> dominoes2={Domino(1,2), Domino(3,2), Domino(3,4), Domino(4,2)};
	Solution2 s2(dominoes2);
	bool res2=s2.existPath(1, 4);
	cout << res2 << endl;
	bool cycle2=s2.existCycle();
	cout << cycle2 << endl;

	vector<Domino> dominoes3={Domino(1,2), Domino(2,3), Domino(3,4), Domino(4,2)};
	Solution3 s3;
	bool res3=s3.existPath(dominoes3, 1, 4);
	cout << res3 << endl;
	bool cycle3=s3.existCycle(dominoes3);
	cout << cycle3 << endl;

	vector<Domino> dominoes4={Domino(1,2), Domino(3,2), Domino(3,4), Domino(4,2)};
	Solution4 s4;
	bool res4=s4.existPath(dominoes4, 1, 4);
	cout << res4 << endl;
	bool cycle4=s4.existCycle(dominoes4);
	cout << cycle4 << endl;

	vector<Domino> dominoes5={Domino(1,2), Domino(2,3), Domino(3,4), Domino(4,2)};
	Solution5 s5(dominoes5);
	bool res5=s5.existPath(1, 4);
	cout << res5 << endl;
	bool cycle5=s5.existCycle();
	cout << cycle5 << endl;

	return 0;
}

