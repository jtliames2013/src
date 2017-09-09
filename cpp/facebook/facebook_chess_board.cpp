 Coding 问的是 有一个无限大的国际象棋棋盘，告诉我 knight 怎么走法， 然后棋盘中有些格子有障碍不能停， 给你起点和终点，返回一个路径。如果没有路径的，返回空。我先是直接用单向的BFS写了一遍，然后说其实应该用双向的BFS，不然如果没有路径的情况，会死循环。因为时间关系，没有实现，他也认可了。

BFS store parent
class Solution {
public:
	vector<pair<int,int>> getNeighbor(pair<int,int> pos) {
		return vector<pair<int,int>> ();
	}

	int myhash(pair<int,int> p) {
		auto h1=hash<int>{}(p.first);
		auto h2=hash<int>{}(p.second);
		return h1^h2;
	}

	vector<pair<int,int>> getPath(pair<int,int> start, pair<int,int> end, unordered_map<int, pair<int,int>>& parent) {
		vector<pair<int,int>> res;
		pair<int,int> p=end;
		while (p!=start) {
			res.push_back(p);
			p=parent[myhash(p)];
		}
		res.push_back(start);
		return res;
	}

	vector<pair<int,int>> findPath(pair<int,int> start, pair<int,int> end) {
		if (start==end) return {start};
		unordered_set<int> visited;
		unordered_map<int, pair<int,int>> parent;
		queue<pair<int,int>> q;
		q.push(start);
		visited.insert(myhash(start));

		while (!q.empty()) {
			pair<int,int> f=q.front();
			q.pop();

			vector<pair<int,int>> neighbors=getNeighbor(f);
			for (auto n:neighbors) {
				if (visited.find(myhash(n))!=visited.end()) {
					parent[myhash(n)]=f;
					if (n==end) return getPath(start, end, parent);
					else q.push(n);
					visited.insert(myhash(n));
				}
			}
		}
	}
};

BFS, queue path
class Solution {
public:
	vector<pair<int,int>> getNeighbor(pair<int,int> pos) {
		return vector<pair<int,int>> ();
	}

	int myhash(pair<int,int> p) {
		auto h1=hash<int>{}(p.first);
		auto h2=hash<int>{}(p.second);
		return h1^h2;
	}

	vector<pair<int,int>> findPath(pair<int,int> start, pair<int,int> end) {
		if (start==end) return {start};
		unordered_set<int> visited;
		queue<vector<pair<int,int>>> q;
		vector<pair<int,int>> v={start};
		q.push(v);
		visited.insert(myhash(start));

		while (!q.empty()) {
			vector<pair<int,int>> path=q.front();
			q.pop();

			pair<int,int> last=path.back();
			vector<pair<int,int>> neighbors=getNeighbor(last);
			for (auto n:neighbors) {
				if (visited.find(myhash(n))!=visited.end()) {
					vector<pair<int,int>> newpath=path;
					newpath.push_back(n);
					if (n==end) return newpath;
					else q.push(newpath);

					visited.insert(myhash(n));
				}
			}
		}
	}
};

