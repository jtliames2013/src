[题目] 只做了一道题，首先给一幅有向图，代表销售网，从A指向B就表示A赚到的钱要分一部分给B，分
的percentage就是边的权重。例如
A -> B, 10%
B -> C, 3%. 
A -> C, 4%

就表示A赚到的钱要分10%给B，4%给C，B赚到的钱要分3%给C。
然后再给每个人的销售额，例如
A 1000

要求计算每个人最后剩多少钱，例如上面的输入，结果应该是
A 860 (1000 * (1 - 10% - 4%)). 
B 97 (1000 * 10% * (1 - 3%))
C 43 (1000 * 4% + 1000 * 10% * 3%

[答题前提问] 做之前问
图有没有环？先假设没有
是不是只有一个根节点？不是. 
是不是只有根节点会输入初始销售额？不是

[解法] 题目不难，想了想应该是拓扑排序，一边说思路一边就码了。
可是因为用的是C，代码看起来会很长，有点脏的感觉，而且还做了很多假设方便处理，比如输入的名字只有一个大写字符啊边的权重都是整数啊什么的，虽然小哥都答应了但是能感受到他觉得有点不耐烦。最后写完编译又出了很多错，因为lz经常打错字……最后还有一个bug是二维数组double matrix[100][100]当参数不能用double** matrix……平时都用的leetcode啊还没有试过传参数进去啊真是要跪了！！！中间改的时候小哥还问你为什么要用C啊，我说其实我常用java，但是都是配合eclipse一起食用，所以面试用C感觉比较保险不会忘语法忘库什么的……又折腾了一会儿终于编译过了，倒是一跑就对了，可是已经自觉都没什么希望了……
Follow up就是问如果有环怎么检测，三行代码的事。然后看我用的邻接矩阵存的图，又问如果给你用java你会怎么改程序呢？一开始还不知道他想问什么，我说没啥改的呀还不是用拓扑排序用queue，后来他说你会怎么存这个图呢？我说哦你想说的邻接表吧？介绍了一下邻接表，然后不知为什么脑抽接着说不过我用java估计还会用邻接矩阵，尽管邻接表省空间……真是前言不搭后语挂电话想了想其实我一直用邻接矩阵只是因为直观啊，真是脑抽了. 
最后感觉小哥已经没什么兴趣了，说没问题了你提问吧，我问了两个问题就提前byebye了。
感觉题目倒是不难（可能难的follow up我没有机会被问到……），不过一次bug free我还差的很远……

struct Person {
	string name;
	float balance;
	Person(string n, float b):name(n), balance(b) {}
};

struct Edge {
	string from;
	string to;
	float weight;
	Edge(string f, string t, float w):from(f), to(t), weight(w) {}
};

class Solution {
public:
	class Compare {
	public:
		bool operator()(pair<string, float> a, pair<string, float> b) {
			return a.first<b.first;
		}
	};
	void getNetworkBalance(vector<Person>& people, vector<Edge>& edges) {
		for (auto p:people) balances[p.name]=p.balance;
		for (auto e:edges) {
			if (graph[e.from].find({e.to, e.weight})==graph[e.from].end()) {
				graph[e.from].insert({e.to, e.weight});
				incomingCnt[e.to]++;
				graph[e.to];
				incomingCnt[e.from];
			}
		}
		set<string> st;
		for (auto vertex:incomingCnt) {
			if (vertex.second==0) st.insert(vertex.first);
		}

		while (!st.empty()) {
			string str=*st.begin();
			st.erase(st.begin());

			float total=balances[str];
			for (auto neighbor:graph[str]) {
				balances[neighbor.first]+=total*neighbor.second;
				balances[str]-=total*neighbor.second;
				incomingCnt[neighbor.first]--;
				if (incomingCnt[neighbor.first]==0) st.insert(neighbor.first);
			}
			graph[str].clear();
		}

		for (auto vertex:graph) {
			if (!vertex.second.empty()) {
				cout << "Cycle in graph!" << endl;
				return;
			}
		}

		printBalance();
	}

	void printBalance() {
		for (auto b:balances) {
			cout << b.first << " " << b.second << endl;
		}
	}
private:
	map<string, float> balances;
	map<string, set<pair<string, float>, Compare> > graph;
	map<string, int> incomingCnt;
};

int main() {
	Solution s;
	vector<Person> people={Person("A", 1000), Person("B", 0), Person("C", 0)};
	//vector<Edge> edges={Edge("A","B",0.1),Edge("B","C",0.03),Edge("A","C",0.04)};
	vector<Edge> edges={Edge("A","B",0.1),Edge("B","C",0.03),Edge("A","C",0.04),Edge("C","B",0.1)};
	s.getNetworkBalance(people, edges);
	return 0;
}

