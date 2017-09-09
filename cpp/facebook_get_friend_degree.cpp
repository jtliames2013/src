用户id是用整数型的，又一个api是可以获得该用户的所有朋友id，如何得到用户a 和b之间的是几度好友需要coding，follow up，空间复杂度，如何优化memory。当时答的用BST和双向BST，跪了。

A->B->C->D 就说明AD是3度好友

1. bi-directional BFS
class Solution {
public:
	unordered_set<int> getFriends(int id) {
		return unordered_set<int>();
	}

	int findFriendDegree(int start, int end) {
		unordered_set<int> st1, st2;
		unordered_set<int> visited;
		st1.insert(start);
		st2.insert(end);
		visited.insert(start);
		visited.insert(end);
		int degree=1;

		if (findHelper(st1, st2, visited, degree)) return degree;
		else return INT_MAX;
	}

	bool findHelper(unordered_set<int>& st1, unordered_set<int>& st2, unordered_set<int>& visited, int& degree) {
		if (st1.size()>st2.size()) return findHelper(st2, st1, visited, degree);
        if (st1.empty()) return false;
        unordered_set<int> next;

		for (auto id:st1) {
			if (st2.find(id)!=st2.end()) return true;
			unordered_set<int> neighbors=getFriends(id);
			for (auto neighbor:neighbors) {
				if (visited.find(neighbor)==visited.end()) {
					next.insert(neighbor);
					visited.insert(neighbor);
				}
			}
		}
		st1.clear();
		degree++;
		return findHelper(st2, next, visited, degree);
	}
};

class Solution {
public:
	unordered_set<int> getFriends(int id) {
		return unordered_set<int>();
	}

	int findFriendDegree(int start, int end) {
		unordered_set<int> st1, st2;
		unordered_set<int> visited;
		st1.insert(start);
		st2.insert(end);
		visited.insert(start);
		visited.insert(end);
		int degree=1;
		unordered_set<int> next;

		while (!st1.empty() && !st2.empty()) {
			while (!st1.empty()) {
				int f=*st1.begin();
				st1.erase(st1.begin());
				if (st2.find(f)!=st2.end()) return degree;
				unordered_set<int> neighbors=getFriends(f);
				for (auto neighbor:neighbors) {
					if (visited.find(neighbor)==visited.end()) {
						next.insert(neighbor);
						visited.insert(neighbor);
					}
				}
			}
			degree++;
			st1=next;
			next.clear();

			while (!st2.empty()) {
				int f=*st2.begin();
				st2.erase(st2.begin());
				if (st1.find(f)!=st1.end()) return degree;
				unordered_set<int> neighbors=getFriends(f);
				for (auto neighbor:neighbors) {
					if (visited.find(neighbor)==visited.end()) {
						next.insert(neighbor);
						visited.insert(neighbor);
					}
				}
			}
			degree++;
			st2=next;
			next.clear();
		}

		return INT_MAX;
	}
};

2. BFS
class Solution {
public:
	unordered_set<int> getFriends(int id) {
		return unordered_set<int>();
	}

	int findFriendDegree(int start, int end) {
		queue<int> q;
		unordered_set<int> visited;
		q.push(start);
		visited.insert(start);
		int degree=1;
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; i++) {
				int f=q.front();
				q.pop();
				if (f==end) return degree;
				unordered_set<int> neighbors=getFriends(f);
				for (auto neighbor:neighbors) {
					if (visited.find(neighbor)==visited.end()) {
						q.push(neighbor);
						visited.insert(neighbor);
					}
				}
			}
			degree++;
		}

		return INT_MAX;
	}
};

